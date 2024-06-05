using Common;
using System.Collections.Generic;

namespace RemotingInterface
{

    public delegate void MessageArrivedEvent(Message msg);
    
    public interface IServerObject
    {
        #region Events

        // event triggered to notify client that a message arrived
        event MessageArrivedEvent MessageArrived;

        #endregion

        #region Methods
        void PublishMessage(Message msg);
        List<string> Subscribe(string username);

        void Unsubscribe(string username);

        void Ping();

        #endregion
    }
}