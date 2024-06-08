const cors = require('cors');
require('dotenv').config();
const express = require('express');
const app = express();
const jwt = require('jsonwebtoken');
const additional = require('./additional')
const cron = require('node-cron');


app.use( 
  cors({ 
    origin: ['http://localhost:3000'], 
    methods: ['GET', 'POST'], 
    credentials: true, 
  }),
); 
app.use(express.json()); 
app.use(express.urlencoded({ extended: true }));
  

/**********************************************/

const users = [
  { username: 'gg', password:'gg', role: 'admin', blockchainAddress: process.env.OWNER_ADDRESS },
  { username: 'Kyle', password: '123', role: 'user', blockchainAddress: process.env.USER_1_ADDRESS },
  { username: 'Jim', password: '321', role: 'user', blockchainAddress: process.env.USER_2_ADDRESS }
];


app.post('/login', (req : any, res : any) => {
  const { username, password } = req.body;
  const user = users.find(user => user.username === username && user.password === password);

  if (user) {
    const accessToken = jwt.sign(
      { username: user.username, role: user.role, blockchainAddress: user.blockchainAddress },
      process.env.ACCESS_TOKEN_SECRET,
      { expiresIn: '1h' } // Срок действия токена
    );
    console.log('Sending role:', user.role);
    res.json({ accessToken, role: user.role, blockchainAddress: user.blockchainAddress });
  } else {
    res.status(401).send('Username or password is incorrect');
  }
});


function authenticateToken(req : any, res : any, next : any){
  const authHeader = req.headers.authorization;
  const token = authHeader && authHeader.split(' ')[1];
  if(!token) return res.sendStatus(401);

  jwt.verify(token, process.env.ACCESS_TOKEN_SECRET, (err : any, user : any) => {
    if (err) return res.sendStatus(403);
    req.user = user;
    next();
  });
}

app.get('/users', authenticateToken, (req : any, res : any) => {
  if (req.user.role !== 'admin') {
    return res.status(403).send('Access Denided: Admins only');
  }
  res.json(users.filter(user => user.username === req.user.username));
});


app.post('/addCandidate', async (req: { body: { name: string; description: string; };}, res : any) => {
  const { name, description } = req.body;
  try {
    await additional.addCandidate(name, description);
    res.status(200).send({ message: "Candidate added successfully" });
  } catch (error : any) {
    console.error("Error occurred:", error);
    res.status(400).send({ error: error.reason || "An error occurred while adding candidate" });
  }
});
   
app.post('/startVoting', async (req : {body:{min: number;};}, res : any) => {
  const { min } = req.body; // Исправление: получение данных из тела запроса
  try {
    const txReceipt = await additional.startVoting(min);
    res.status(200).send(txReceipt); // Отправка данных о квитанции
  } catch (error : any) {
    //console.error("Error starting voting:", error);
    res.status(500).send({ error: error.reason || "Failed to start voting due to an unexpected error" });
  }
});


app.get('/votingStatus', async (req : any, res  : any) => {
  try {
    const status = await additional.getVotingStatus();
   // console.log('Server Voting Status:', status); // Добавлено логирование
    const { isVotingActive, startTime, endTime, totalVotesCount } = status;
    res.json({ isVotingActive, startTime, endTime, totalVotesCount });
  } catch (error) {
    console.error('Error fetching voting status:', error);
    res.status(500).send('Error fetching voting status');
  }
});


app.post('/endVoting', async (req : any, res : any) => {
  try {
      const winners = await additional.endVoting();
      res.json({ winners }); // Отправляем объект с массивом победителей
  } catch (error : any) {
      console.error('Error while ending voting:', error.shortMessage);
      res.status(500).send({ error: error.shortMessage || 'Failed to end voting' });
  }
});

app.get('/winners', async (req : any, res : any) => {
  try {
      const winners = await additional.getWinners(); // Эта функция должна возвращать победителей
      res.json({ winners });
  } catch (error : any) {
      console.error('Error fetching winners:', error);
      res.status(500).send({ error: error.message || 'Failed to fetch winners' });
  }
});

app.post('/Vote', async (req:{body:{candidateID : number, signerAddress : any};}, res : any) => {
  const { candidateID, signerAddress } = req.body;
  try {
      const txReceipt = await additional.vote(candidateID, signerAddress);
      res.send(txReceipt);
  } catch (error: any) {
      console.log('Error while voting: ', error);
      res.status(500).send({ error: error.reason || 'Failed to vote' });
  }
});


app.post('/getCandidate', async (req:{body:{candidateID : number, signerAddress : any};}, res : any) => {
  const { candidateID, signerAddress } = req.body;
  try {
      const candidate = await additional.getCandidate(candidateID, signerAddress);
      console.log("Retrieved candidate data:", candidate);
      res.json(candidate);
      console.log(candidate + " success");
  } catch (error: any) {
      console.log('Error retrieving candidate:', error);
      res.status(500).send({ error: error.shortMessage || 'Failed to retrieve candidate' });
  }
});

app.get('/candidates', async (req : any, res : any) => {
  try {
    const candidates = [];
    let candidateID = 1;
    const signerAddress = process.env.OWNER_ADDRESS; // Используем адрес администратора для вызова

    while (true) {
      try {
        const candidate = await additional.getCandidate(candidateID, signerAddress);
        candidates.push(candidate);
        candidateID++;
      } catch (error : any) {
        // Если ошибка - "Invalid candidate ID", завершаем цикл
        if (error.message.includes('Invalid candidate ID')) {
          break;
        } else {
          console.error('Error retrieving candidate:', error);
          return res.status(500).send({ error: 'Failed to retrieve candidates' });
        }
      }
    }
    res.json(candidates);
  } catch (error) {
    console.error('Error fetching candidates:', error);
    res.status(500).send({ error: 'Failed to fetch candidates' });
  }
});


app.post('/verifyVoter', async (req:{body:{addressVoter : any, signerAddress : any};}, res : any)=> {
  const { addressVoter, signerAddress } = req.body;
  console.log("addressVoter: "+ addressVoter + "\nsingerAddress: " + signerAddress);
  try {
    const hasVoted = await additional.verifyVoter(addressVoter, signerAddress);
    console.log("Verification result:", hasVoted )
    res.json({ hasVoted });
} catch (error: any) {
    console.log('Error verifying voter: ', error);
    res.status(500).send({ error: error.reason || 'Failed to verify voter' });
}
});

    
app.listen(3002);

cron.schedule('* * * * *', async () => {
  try {
    const status = await additional.getVotingStatus();
    const { isVotingActive, endTime } = status;
    const currentTime = Math.floor(Date.now() / 1000);

    if (isVotingActive === 'true' && currentTime >= endTime) {
      console.log('Voting period has ended. Automatically ending the voting.');
      await additional.endVoting();
    }
  } catch (error) {
    console.error('Error checking voting status:', error);
  }
});

function async(req: any, res: any): any {
  throw new Error("Function not implemented.");
}

