//Approach-1 (Using O(n) space)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return -1;  // Edge case: empty array
        vector<int> cumSum(n,0);
        cumSum[0] = nums[0];
        int totalSum = nums[0];
        for(int i=1;i<n;i++){
            cumSum[i] = cumSum[i-1] + nums[i];
            totalSum += nums[i];
        }

        for(int i =0;i<n;i++){
            int leftSum = (i==0) ? 0 : cumSum[i-1];
            int rightSum = totalSum - leftSum - nums[i];
            if(leftSum == rightSum){
                return i;
            }
        }
        return -1;
    }
};



//Approach-2 (Using O(1) space)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i=0;i<n;i++){
            totalSum += nums[i];
        }

        int currSum = 0;
        for(int i=0;i<n;i++){
            int leftSum = currSum;
            int rightSum = totalSum - leftSum - nums[i];
            if(leftSum==rightSum){
                return i;
            }
            currSum += nums[i];
        }
        return -1;
    }
};
