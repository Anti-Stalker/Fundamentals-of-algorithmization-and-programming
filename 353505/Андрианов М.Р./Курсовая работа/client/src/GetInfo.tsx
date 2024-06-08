import React, { useState, useEffect } from 'react';
import axios from 'axios';
import { Link } from 'react-router-dom';
import './GetInfo.css';

const GetInfo: React.FC = () => {
  const [candidateID, setCandidateID] = useState<number>(0);
  const [addressVoter, setAddressVoter] = useState<string>('');
  const [candidateInfo, setCandidateInfo] = useState<any>(null);
  const [hasVoted, setHasVoted] = useState<boolean | null>(null);
  const [loading, setLoading] = useState<boolean>(false);
  const [errorMessage, setErrorMessage] = useState<string>('');
  const [signerAddress, setSignerAddress] = useState<string | null>(null);
  const [winners, setWinners] = useState<any[]>([]);

  useEffect(() => {
    const storedSignerAddress = sessionStorage.getItem('blockchainAddress');
    setSignerAddress(storedSignerAddress);

    const fetchWinners = async () => {
      try {
        const response = await axios.get('http://localhost:3002/winners');
        setWinners(response.data.winners);
      } catch (error) {
        console.error('Error fetching winners:', error);
        setErrorMessage('Failed to fetch winners');
      }
    };

    fetchWinners();
  }, []);

  const handleGetCandidate = async () => {
    setLoading(true);
    setErrorMessage('');
    try {
      const response = await axios.post('http://localhost:3002/getCandidate', { candidateID, signerAddress });
      setCandidateInfo(response.data);
    } catch (error: any) {
      console.error('Error retrieving candidate:', error);
      setErrorMessage(error.response ? error.response.data.error : "Unexpected error");
    } finally {
      setLoading(false);
    }
  };

  const handleVerifyVoter = async () => {
    setLoading(true);
    setErrorMessage('');
    try {
      const response = await axios.post('http://localhost:3002/verifyVoter', { addressVoter, signerAddress });
      setHasVoted(response.data.hasVoted);
      console.log("Voter has voted:", response.data.hasVoted);
    } catch (error: any) {
      console.error('Error verifying voter:', error);
      setErrorMessage("Failed to verify voter: " + (error.response ? error.response.data.error : "Unexpected error"));
    } finally {
      setLoading(false);
    }
  };

  return (
    <div className="getinfo-container">
      <nav className="nav-back">
        <Link to="/home">
          <button>Back</button>
        </Link>
      </nav>
      <div className="getinfo-card">
        {winners.length > 0 && (
          <div className="winner-info">
            {winners.length > 1 && <h2>Winners:</h2>}
            {winners.map((winner, index) => (
              <div key={index}>
                <h1>Winner: {winner.name}</h1>
                <p>Description: {winner.description}</p>
                <p>Votes: {winner.voteCount}</p>
                <p>Percent: {winner.percent}%</p>
              </div>
            ))}
          </div>
        )}
        <h1>Show Candidate Information</h1>
        <input
          type="number"
          value={candidateID}
          onChange={e => setCandidateID(parseInt(e.target.value, 10))}
          placeholder="Candidate ID"
        />
        <button onClick={handleGetCandidate} disabled={loading}>
          {loading ? 'Loading...' : 'Get Candidate'}
        </button>
        {candidateInfo && (
          <div>
            <h2>Candidate Details</h2>
            <p>Name: {candidateInfo.name}</p>
            <p>Description: {candidateInfo.description}</p>
            <p>Votes: {candidateInfo.voteCount}</p>
          </div>
        )}
        <h1>Verify Voter</h1>
        <input
          type="text"
          value={addressVoter}
          onChange={e => setAddressVoter(e.target.value)}
          placeholder="0x..."
        />
        <button onClick={handleVerifyVoter} disabled={loading}>
          {loading ? 'Verifying...' : 'Verify Voter'}
        </button>
        {hasVoted !== null && (
          <p>{hasVoted ? "Voter has voted." : "Voter has not voted."}</p>
        )}
        {errorMessage && <p className="error-message">Error: {errorMessage}</p>}
      </div>
    </div>
  );
};

export default GetInfo;
