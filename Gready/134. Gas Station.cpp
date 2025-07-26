class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i=0;i<n;i++){
            if(gas[i]<cost[i]){
                continue;
            }
            int j = (i+1)%n;

            int costToMoveAhead = cost[i];
            int reward = gas[j];

            int currGas = gas[i] - costToMoveAhead + reward;

            while(j!=i){
                if(currGas < cost[j]) break;

                int costToMoveAheadj = cost[j];
                j = (j+1)%n;

                int rewardj = gas[j];

                currGas = currGas - costToMoveAheadj + rewardj;
            }

            if(i==j) return i;
        }
        return -1;
    }
};


// Optimal 
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n= gas.size();

        int totalAvl = accumulate(begin(gas),end(gas),0);
        int totalCost = accumulate(begin(cost),end(cost),0);

        if(totalAvl < totalCost) return -1;

        int total = 0;
        int result = 0;

        for(int i=0;i<n;i++){
            total = total + gas[i] - cost[i];

            if(total < 0){
                result = i+1;
                total = 0;
            }

        }
        return result;
    }
};
