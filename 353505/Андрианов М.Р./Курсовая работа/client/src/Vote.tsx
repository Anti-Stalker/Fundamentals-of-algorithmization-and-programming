import React, { useState, useEffect } from 'react';
import axios from 'axios';
import { Link } from 'react-router-dom';
import './Vote.css';

const Vote: React.FC = () => {
  const [voteStatus, setVoteStatus] = useState<string>('');
  const [signerAddress, setSignerAddress] = useState<string | null>(null);
  const [votingStatus, setVotingStatus] = useState<string>('Voting not started');
  const [errorMessage, setErrorMessage] = useState<string>('');
  const [candidates, setCandidates] = useState<any[]>([]);
  const [votedCandidateID, setVotedCandidateID] = useState<number | null>(null);

  useEffect(() => {
    const storedSignerAddress = sessionStorage.getItem('blockchainAddress');
    setSignerAddress(storedSignerAddress);

    const fetchVotingStatus = async () => {
      try {
        const response = await axios.get('http://localhost:3002/votingStatus');
        const { isVotingActive, startTime, endTime, totalVotesCount } = response.data;
        console.log('Client Voting Status:', { isVotingActive, startTime, endTime, totalVotesCount });

        if (isVotingActive === true || isVotingActive === 'true') {
          setVotingStatus('Voting is active');
        } else if (totalVotesCount > 0) {
          setVotingStatus('Voting has ended');
        } else {
          setVotingStatus('Voting not started');
        }
      } catch (error) {
        console.error('Error fetching voting status:', error);
        setErrorMessage('Error fetching voting status');
      }
    };

    const fetchCandidates = async () => {
      const allCandidates = [];
      let candidateID = 1;
      while (true) {
        try {
          const response = await axios.post('http://localhost:3002/getCandidate', { candidateID, signerAddress });
          allCandidates.push(response.data);
          candidateID++;
        } catch (error: any) {
          if (axios.isAxiosError(error) && error.response && error.response.data.error === "Invalid candidate ID") {
            break;
          }
          break;
        }
      }
      setCandidates(allCandidates);
    };

    fetchVotingStatus();
    fetchCandidates();
  }, [signerAddress]);

  const handleVote = async (candidateID: number, candidateName: string) => {
    setVoteStatus('');
    const confirmed = window.confirm(`Вы действительно хотите проголосовать за кандидата ${candidateName}?`);
    if (!confirmed) {
      return;
    }
    try {
      await axios.post('http://localhost:3002/Vote', { candidateID, signerAddress });
      setVoteStatus('Vote successful');
      setVotedCandidateID(candidateID); // Highlight the voted candidate
    } catch (error) {
      if (axios.isAxiosError(error) && error.response) {
        console.error('Error ending the voting:', error.response.data.error || error.message);
        setVoteStatus(`Failed to vote: ${error.response.data.error || error.message}`);
      } else {
        console.error('Unexpected error:', error);
        setVoteStatus("An unexpected error occurred");
      }
    }
  };

  return (
    <div className="vote-container">
      <nav className="nav-back">
        <Link to="/home">
          <button>Back</button>
        </Link>
      </nav>
      <div className="vote-card">
        <h1>Vote for Candidate</h1>
        <div><h3>Voting Status:</h3><p>{votingStatus}</p></div>
        {errorMessage && <div className="error-message"><h3>Error:</h3><p>{errorMessage}</p></div>}
        <div>
          {candidates.length > 0 && (
            <div>
              <h2>Candidates:</h2>
              {candidates.map((candidate) => (
                <div
                  key={candidate.candidateID}
                  onClick={() => handleVote(candidate.candidateID, candidate.name)}
                  className={`candidate-card ${votedCandidateID === candidate.candidateID ? 'successful-vote' : ''}`}
                >
                  <div>
                    <h3>{candidate.name}</h3>
                    <p>{candidate.description}</p>
                  </div>
                  <div className={`checkbox ${votedCandidateID === candidate.candidateID ? 'checked' : ''}`}>
                    {votedCandidateID === candidate.candidateID && '✔'}
                  </div>
                </div>
              ))}
            </div>
          )}
        </div>
        {voteStatus && <div className="vote-status"><p>{voteStatus}</p></div>}
      </div>
    </div>
  );
};

export default Vote;
