import React, { useState } from 'react';
import axios from 'axios';
import { Link } from 'react-router-dom';
import './AddCandidateForm.css';

const AddCandidateForm: React.FC = () => {
  const [candidateName, setCandidateName] = useState('');
  const [candidateDescription, setCandidateDescription] = useState('');
  const [responseMessage, setResponseMessage] = useState('');
  const [loading, setLoading] = useState<boolean>(false);

  const handleSubmit = async (event: React.FormEvent) => {
    event.preventDefault();
    setResponseMessage('');

    if (!candidateName.trim()) {
      setResponseMessage('Candidate name cannot be empty.');
      return;
    }

    setLoading(true);
    try {
      const response = await axios.post('http://localhost:3002/addCandidate', {
        name: candidateName,
        description: candidateDescription
      });
      setResponseMessage("Candidate " + candidateName + " added successfully");
    } catch (error) {
      if (axios.isAxiosError(error) && error.response && error.response.data.error) {
        setResponseMessage(error.response.data.error);
      } else {
        setResponseMessage('Unexpected error');
      }
    }
    setLoading(false);
  };

  return (
    <div className="add-candidate-container">
      <nav className="nav-back">
        <Link to="/home">
          <button>Back</button>
        </Link>
      </nav>
      <div className="add-candidate-card">
        <h1>Add Candidate</h1>
        <form onSubmit={handleSubmit}>
          <div>
            <label>
              Candidate Name:
              <input
                type="text"
                value={candidateName}
                onChange={e => setCandidateName(e.target.value)}
              />
            </label>
          </div>
          <div>
            <label>
              Candidate Description:
              <input
                type="text"
                value={candidateDescription}
                onChange={e => setCandidateDescription(e.target.value)}
              />
            </label>
          </div>
          <button type="submit" disabled={loading}>
            {loading ? 'Submitting...' : 'Add Candidate'}
          </button>
        </form>
        {responseMessage && <p className="response-message">{responseMessage}</p>}
      </div>
    </div>
  );
};

export default AddCandidateForm;
