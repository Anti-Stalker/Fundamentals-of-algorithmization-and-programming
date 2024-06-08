const { ethers } = require("ethers");
import { JsonRpcProvider } from "ethers";

const LockArtifact = require('../blockchain/artifacts/contracts/Lock.sol/Lock.json'); 
const contractAddressArtifact = require('../blockchain/ignition/deployments/chain-31337/deployed_addresses.json');

const contractABI: any[] = LockArtifact.abi;
const contractAddress: string = contractAddressArtifact['LockModule#Lock']; 
const provider = new JsonRpcProvider('http://127.0.0.1:8545'); 

const owner: any = new ethers.Wallet(
  process.env.OWNER_PRIVATE_KEY,
  provider,
);
const contract = new ethers.Contract(contractAddress, contractABI, provider);

let winnersCache: any[] = [];

async function endVoting() {
  const winners: { candidateID: string; name: string; description: string; voteCount: string; percent: string; }[] = [];

  const winnerListener = (candidateID: number, name: string, description: string, voteCount: number, percent: number) => {
    console.log(`Winner: ${name}, Description: ${description}, Votes: ${voteCount}, Percent: ${percent}%`);
    winners.push({
      candidateID: candidateID.toString(),
      name,
      description,
      voteCount: voteCount.toString(),
      percent: percent.toString()
    });
  };

  contract.on("WinnerDeclared", winnerListener);

  try {
    const txResponse = await contract.connect(owner).endVoting();
    const txReceipt = await txResponse.wait();
    console.log(txReceipt);

    await new Promise(resolve => setTimeout(resolve, 500));

    contract.off("WinnerDeclared", winnerListener);

    console.log("Collected winners:", winners);
    winnersCache = winners;
    return winners;
  } catch (error) {
    console.error('Error during the voting end:', error);
    contract.off("WinnerDeclared", winnerListener);
    throw error;
  }
}

async function getWinners() {
  return winnersCache;
}


async function addCandidate(name: string, description: string) {
    const txResponse = await contract.connect(owner).addCandidate(name, description);
    const txReceipt = await txResponse.wait();
    console.log('Transaction receipt:', txReceipt); 
}

async function startVoting(min : number){
    const txResponse = await contract.connect(owner).startVoting(min);
    const txReceipt = await txResponse.wait();
    console.log(txReceipt);
}

async function vote(candidateID : number, signerAddress : string){
    const signer = await provider.getSigner(signerAddress);
    const txResponse = await contract.connect(signer).vote(candidateID);
    console.log(txResponse);
}
//vote(2, '0x90F79bf6EB2c4f870365E785982E1f101E93b906') 

async function getCandidate(candidateID: number, signerAddress: any) {
    const signer = await provider.getSigner(signerAddress);
    try {
        const candidate = await contract.connect(signer).getCandidate(candidateID);
        // Логирование ответа для отладки
        console.log(`Retrieved candidate:`, candidate);

        // Проверяем, что кандидат действительно возвращается
        if (!candidate) {
            throw new Error('Candidate not found');
        }

        // Форматирование и возвращение данных кандидата
        const candidateData = {
            candidateID: candidateID.toString(), // Преобразование ID кандидата в строку
            name: candidate.name,                // Имя кандидата
            description: candidate.description,  // Описание кандидата
            voteCount: candidate.voteCount.toString() // Преобразование количества голосов в строку
        };

        // Возвращаем преобразованные данные
        return candidateData;
    } catch (error) {
        console.error('Error retrieving candidate:', error);
        throw error;
    }
}

async function verifyVoter(addressVoter: string, signerAddress: string): Promise<boolean> {
    try {
        const signer = await provider.getSigner(signerAddress); // Получение подписанта по адресу
        const txResponse = await contract.connect(signer).verifyVoter(addressVoter);
        return txResponse.toString() === "true";
    } catch (error) {
        console.error("Error verifying voter:", error);
        return false; // В случае ошибки, считаем что проверка не прошла
    }
}

async function getVotingStatus() {
    const status = await contract.getVotingStatus();
    console.log('Contract Voting Status:', status); // Добавлено логирование
    return {
        isVotingActive: status[0].toString(),
        startTime: status[1].toString(),
        endTime: status[2].toString(),
        totalVotesCount: status[3].toString()
    };
}
getVotingStatus()

  
module.exports={
    endVoting,
    addCandidate,
    startVoting,
    vote,
    getCandidate,
    verifyVoter,
    getVotingStatus,
    getWinners
};
