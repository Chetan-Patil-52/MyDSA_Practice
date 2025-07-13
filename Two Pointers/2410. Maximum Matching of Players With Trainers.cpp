class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int m = players.size();
        int n = trainers.size();
        int i=0;
        int j=0;
        int cnt = 0;
        sort(begin(players),end(players));
        sort(begin(trainers),end(trainers));
        while(j<n && i<m){
            if(players[i]<=trainers[j]){
                cnt++;
                i++;
            }
            j++;
        }
        return cnt;
    }
};
