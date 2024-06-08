import { Routes, Route, Link, Navigate } from 'react-router-dom';
import React from 'react';
import Login, { user } from './Login';
import VotingComponent from './VotingComponent';
import AddCandidateForm from './AddCandidateForm';
import Vote from './Vote';
import GetInfo from './GetInfo';
import Home from './Home';

const App: React.FC = () => {
  return (
      <div className="App">
       <Routes>
          <Route path="/" element={<Login />} />
          <Route path="/home" element={<Home/>} />
          <Route path="/voting_component" element={<VotingComponent/>}/> 
          <Route path="/addCandidate" element={<AddCandidateForm />} /> 
          <Route path="/vote" element={<Vote/>} />
          <Route path="/getInfo" element={<GetInfo/>} />
        </Routes>
      </div>
  );
};

/*const App : React.FC = () => {
  return (
    <div className="App">
      <Routes>
        <Route path="/" element={<Login />} />
        <Route path="/home" element={<Home/>} />
        <Route path="/vote" element={<Vote/>} />
        <Route path="/getInfo" element={<GetInfo/>} />
        <Route path="/voting_component" element={user.role === 'admin' ? <VotingComponent/> : <Navigate to="/home" />} />
        <Route path="/addCandidate" element={user.role === 'admin' ? <AddCandidateForm/> : <Navigate  to='/home'/>} />
      </Routes>
    </div>
  )
}*/

export default App;
