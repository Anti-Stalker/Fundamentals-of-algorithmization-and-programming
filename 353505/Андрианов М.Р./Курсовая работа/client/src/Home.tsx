import React, { useEffect, useState } from 'react';
import { Link } from 'react-router-dom';
import './Home.css';

const Home: React.FC = () => {
  const [role, setRole] = useState<string | null>(null);
  const [username, setUsername] = useState<string | null>(null);

  useEffect(() => {
    const storedRole = sessionStorage.getItem('role');
    const storedUsername = sessionStorage.getItem('username');
    console.log('Role from sessionStorage:', storedRole);
    console.log('Username from sessionStorage:', storedUsername);
    setRole(storedRole);
    setUsername(storedUsername);
  }, []);

  return (
    <div className="home-container">
      <div className="home-card">
        <h1>Welcome, {username}</h1>
        {role === 'admin' ? (
          <p>You have logged in as <span className="admin-role">Admin</span></p>
        ) : (
          <p>You have logged in as <span className="user-role">User</span></p>
        )}
        <Link to="/" onClick={() => sessionStorage.clear()} className="logout-link">Log Out</Link>
        <nav className="home-nav">
          <ul>
            {role === 'admin' && (
              <>
                <li><Link to="/voting_component" className="nav-link">Voting Component</Link></li>
                <li><Link to="/addCandidate" className="nav-link">Add Candidate</Link></li>
              </>
            )}
            <li><Link to="/vote" className="nav-link">Vote</Link></li>
            <li><Link to="/getInfo" className="nav-link">Get Info</Link></li>
          </ul>
        </nav>
      </div>
    </div>
  );
};

export default Home;
