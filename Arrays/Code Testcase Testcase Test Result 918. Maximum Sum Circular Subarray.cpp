
//BT
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        long long maxi = LONG_MIN;
        for(int i=0;i<n;i++){
            long long sum = 0;
            for(int j=i+1;j<n;j++){
                sum += nums[j];
                maxi = max(maxi,sum);
            }
            for(int j=0;j<=i;j++){
                sum += nums[j];
                maxi = max(maxi,sum);
            }
        }
        return maxi;
    }
};

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // Using Kaden's Algorithm

        int maxSum = nums[0], currMax = 0;
        int minSum = nums[0], currMin = 0;
        int total = 0;

        for(int num : nums){

            currMax = max(currMax+num,num);
            maxSum = max(currMax,maxSum);

            currMin = min(currMin+num,num);
            minSum = min(minSum,currMin);

            total += num;
        }

        if(maxSum < 0) return maxSum;

        return max(maxSum,total-minSum);
    }
};
