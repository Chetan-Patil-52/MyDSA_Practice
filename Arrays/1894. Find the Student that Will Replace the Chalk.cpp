class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        int idx = 0;
        while(k > 0 ){
            int mod = idx%n;
            if((k-chalk[mod]) >= 0){
                idx++;
            }
            k -= chalk[mod];
        }

        return idx%n;
    }
};

// Optimal
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long t = 0;
        for(int num : chalk){
            t+= num;
        }

        int remaining = k%t;
        for(int i=0;i<n;i++){
            if(remaining < chalk[i]){
                return i;
            }
            remaining -= chalk[i];
        }

        return -1;
    }
};
