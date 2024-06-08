import React, { useState } from 'react';
import axios from 'axios';
import { useNavigate } from 'react-router-dom';
import './Login.css';

interface UserState {
  username: string;
  role: string;
  blockchainAddress: string;
}

export let user: UserState = {
  username: '',
  role: '',
  blockchainAddress: ''
};

const Login: React.FC = () => {
  const [username, setUsername] = useState('');
  const [password, setPassword] = useState('');
  const [errorMessage, setErrorMessage] = useState<string>(''); // Состояние для хранения сообщений об ошибках
  const navigate = useNavigate();

  const handleSubmit = async (event: { preventDefault: () => void; }) => {
    event.preventDefault();
    try {
      const response = await axios.post('http://localhost:3002/login', { username, password });
      const { accessToken, role, blockchainAddress } = response.data;
      console.log('Login successful with role:', role, 'and blockchain address:', blockchainAddress);
      
      if (accessToken) {
        sessionStorage.setItem('accessToken', accessToken);
        sessionStorage.setItem('username', username); // Сохраняем имя пользователя в sessionStorage
        sessionStorage.setItem('role', role);
        sessionStorage.setItem('blockchainAddress', blockchainAddress);
        user.username = username;
        user.role = role;
        user.blockchainAddress = blockchainAddress;
  
        navigate('/home');
      }
    } catch (error: any) {
      const errorMsg = error.response ? error.response.data : error.message;
      setErrorMessage(errorMsg);
      console.error('Login error:', errorMsg);
    }
  };

  return (
    <div className="login-container">
      <h1 className="login-title">Decentralized Voting System</h1>
      <form onSubmit={handleSubmit} className="login-form">
        <div className="form-group">
          <label htmlFor="username">Username:</label>
          <input
            id="username"
            type="text"
            value={username}
            onChange={e => setUsername(e.target.value)}
            className="form-control"
          />
        </div>
        <div className="form-group">
          <label htmlFor="password">Password:</label>
          <input
            id="password"
            type="password"
            value={password}
            onChange={e => setPassword(e.target.value)}
            className="form-control"
          />
        </div>
        {errorMessage && <div className="error-message">{errorMessage}</div>}
        <button type="submit" className="login-button">Login</button>
      </form>
    </div>
  );
};

export default Login;
