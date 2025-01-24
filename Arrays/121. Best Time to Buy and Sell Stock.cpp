// TC : O(N+N) -> O(N) SC -> O(N)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> vec(n);
        vec[0] = prices[0];
        for(int i=1;i<n;i++){
            vec[i] = min(vec[i-1],prices[i]);
        }

        int max_profit = 0;
        for(int i=0;i<n;i++){
            int curr_profit = prices[i] - vec[i];
            max_profit = max(curr_profit,max_profit);
        }

        return max_profit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> vec(n);
        vec[0] = prices[0];
        for(int i=1;i<n;i++){
            vec[i] = min(vec[i-1],prices[i]);
        }

        int max_profit = 0;
        for(int i=0;i<n;i++){
            int curr_profit = prices[i] - vec[i];
            max_profit = max(curr_profit,max_profit);
        }

        return max_profit;
    }
};
