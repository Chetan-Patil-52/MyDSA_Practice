// Learnigns - 
// debugged one err cause becuase of referencing MLE on line number 58.
// Had to pass it by refence buecuase it was passed by value earlier. 
// Knewed erlier that had to implement queue here.

class Router {
public:
    int MAX_SIZE; // Usend for intitialization 
    unordered_map<string,vector<int>> packetStore;
    unordered_map<int, vector<int>> destTimestamp;
    queue<string> que;// FIFO ordering
    Router(int memoryLimit) {
        MAX_SIZE = memoryLimit;
    }
    
    string makeKey(int source, int destination, int timestamp){
        return to_string(source) + "_" + to_string(destination) + "_" +to_string(timestamp);
    }

    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source,destination,timestamp);
        
        if(packetStore.find(key) != packetStore.end()){
            return false;
        }

        if((int)packetStore.size() >= MAX_SIZE){
            forwardPacket();
        }

        packetStore[key] = {source,destination,timestamp};
        que.push(key);
        destTimestamp[destination].push_back(timestamp);

        return true;
    }
    
    vector<int> forwardPacket() {
        if(packetStore.empty()){
            return {};
        }
        string key = que.front();
        que.pop();

        vector<int> packet = packetStore[key];
        packetStore.erase(key);

        int dest = packet[1];
        destTimestamp[dest].erase(destTimestamp[dest].begin());
        return packet;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto it = destTimestamp.find(destination);

        if(it == destTimestamp.end() || it->second.empty()){
            return 0;
        }
        
        vector<int> &timeStamps = destTimestamp[destination];
        int i = lower_bound(begin(timeStamps),end(timeStamps),startTime)-begin(timeStamps);
        int j = upper_bound(begin(timeStamps),end(timeStamps),endTime)-begin(timeStamps);

        return j-i;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
