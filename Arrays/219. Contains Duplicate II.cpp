class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // Approach - 1 (Bruteforce)
        // int n = nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(i==j){
        //             continue;
        //         }
        //         if(nums[i]==nums[j]){
        //             if(abs(i-j)<=k){
        //                 return true;
        //             }
        //         }
        //     }
        // }
        // return false;

        // Approach - 2 (Using map)
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i]) != mp.end() && i-mp[nums[i]] <= k){
                return true;
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};
