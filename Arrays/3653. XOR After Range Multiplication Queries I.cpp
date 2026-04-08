class Solution {
public:
    int M = 1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        // Simple Simulation Problem
        // Perfrom all the Queries on array and then simple perform xor
        int n = nums.size();
        int m = queries.size();
        int query = 0;
        while(query < m){
            int l = queries[query][0];
            int r = queries[query][1];
            int k = queries[query][2];
            int v = queries[query][3];
            for(int i=l;i<=r;i+=k){
                nums[i] = (1LL * nums[i] * v) % M;
            }
            query++;
        }

        // Simply Perform XOR
        int xOR = 0;
        for(int i=0;i<n;i++){
            xOR ^= nums[i];
        }

        return xOR;
    }
};
