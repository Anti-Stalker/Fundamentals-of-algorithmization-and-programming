import React, { useState, useEffect } from 'react';
import axios from 'axios';
import { Link } from 'react-router-dom';
import './VotingComponent.css';

interface Winner {
  name: string;
  description: string;
  voteCount: string;
  percent: string;
}

const VotingComponent: React.FC = () => {
  const [min, setMin] = useState<number>(0);
  const [loading_1, setLoading_1] = useState<boolean>(false);
  const [loading_2, setLoading_2] = useState<boolean>(false);
  const [votingStatus, setVotingStatus] = useState<string>('Voting not started');
  const [errorMessage, setErrorMessage] = useState<string>('');
  const [winners, setWinners] = useState<Winner[]>([]);

  useEffect(() => {
    const fetchVotingStatus = async () => {
      try {
        const response = await axios.get('http://localhost:3002/votingStatus');
        const { isVotingActive, startTime, endTime, totalVotesCount } = response.data;
        console.log('Client Voting Status:', { isVotingActive, startTime, endTime, totalVotesCount });

        if (isVotingActive === true || isVotingActive === 'true') {
          setVotingStatus('Voting is active');
        } else if (totalVotesCount > 0) {
          setVotingStatus('Voting has ended');
          await fetchWinners();
        } else {
          setVotingStatus('Voting not started');
        }
      } catch (error) {
        console.error('Error fetching voting status:', error);
      }
    };

    fetchVotingStatus();
  }, []);

  const fetchWinners = async () => {
    try {
      const response = await axios.get('http://localhost:3002/winners');
      setWinners(response.data.winners || []);
      console.log("Received winner data:", response.data.winners);
    } catch (error) {
      console.error('Error fetching winners:', error);
      setErrorMessage('Failed to fetch winners');
    }
  };

  const handleStartVoting = async () => {
    setLoading_1(true);
    setErrorMessage('');
    if (min < 1 || min > 720) {
      setErrorMessage("Please enter the duration between 1 and 720 minutes.");
      setLoading_1(false);
      return;
    }
    try {
      await axios.post('http://localhost:3002/startVoting', { min });
      setVotingStatus('Voting is active');
    } catch (error) {
      if (axios.isAxiosError(error) && error.response) {
        console.error('Error starting the voting:', error.response.data.error || error.message);
        setErrorMessage("Failed to start voting: " + (error.response.data.error || "Unexpected error"))
      } else {
        console.error('Unexpected error:', error);
        setErrorMessage("Unexpected error occurred");
      }
    }
    setLoading_1(false);
  };

  const handleInputChange = (e: React.ChangeEvent<HTMLInputElement>) => {
    const value = parseInt(e.target.value, 10);
    setMin(isNaN(value) ? 0 : value);
  };

  const handleEndVoting = async () => {
    setLoading_2(true);
    setErrorMessage('');
    try {
      const response = await axios.post('http://localhost:3002/endVoting');
      setVotingStatus('Voting has ended');
      setWinners(response.data.winners || []);
      console.log("Received winner data:", response.data.winners);
    } catch (error: any) {
      console.error('Error ending the voting:', error);
      setErrorMessage(error.response ? error.response.data.error : "Unexpected error");
    } finally {
      setLoading_2(false);
    }
  };

  return (
    <div className="voting-container">
      <nav className="nav-back">
        <Link to="/home">
          <button>Back</button>
        </Link>
      </nav>
      <div className="voting-card">
        <h1>Start Voting</h1>
        <input
          type="number"
          value={min.toString()}
          onChange={handleInputChange}
          placeholder="Minutes"
        />
        <button onClick={handleStartVoting} disabled={loading_1}>
          {loading_1 ? 'Processing...' : 'Start Voting'}
        </button>
        <button onClick={handleEndVoting} disabled={loading_2}>
          {loading_2 ? 'Processing...' : 'End Voting'}
        </button>
        <div className="status"><h3>Voting Status:</h3><p>{votingStatus}</p></div>
        {errorMessage && <div className="error"><h3>Error:</h3><p>{errorMessage}</p></div>}
        {winners.length > 0 && (
          <div className="winner-container">
            {winners.length > 1 && <h2>Winners:</h2>}
            {winners.map((winner, index) => (
              <div key={index} className="winner-card">
                <h3>Winner: {winner.name}</h3>
                <p>Description: {winner.description}</p>
                <p>Votes: {winner.voteCount}</p>
                <p>Percent: {winner.percent}%</p>
              </div>
            ))}
          </div>
        )}
      </div>
    </div>
  );
};

export default VotingComponent;
