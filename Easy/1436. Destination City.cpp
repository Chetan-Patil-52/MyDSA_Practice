// Using Hash_map
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int>  mp;
        for(auto &path : paths){
            string source = path[0];
            mp[source]++;
        }

        for(auto &path : paths){
            string destination = path[1];
            if(mp[destination] != 1){
                return destination;
            }
        }
        return "IIT Baba";
    }
};

// Using Hash_set

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string>  st;
        for(auto &path : paths){
            string source = path[0];
            st.insert(source);
        }

        for(auto &path : paths){
            string destination = path[1];
            if(st.find(destination) == st.end()){
                return destination;
            }
        }
        return "IIT Baba";
    }
};
