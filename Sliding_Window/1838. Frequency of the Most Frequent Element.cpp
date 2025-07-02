class Solution {
public:

    int findBest(int target_idx,int k,vector<int>& nums,vector<long>& prefixSum){
        int target = nums[target_idx];
        int i=0,j=target_idx;
        int result = target_idx;
         while(i<=j){
            int mid = i+(j-i)/2;

            long count = target_idx - mid + 1;
            long windowSum = count*target;
            long currSum = prefixSum[target_idx] -prefixSum[mid]+nums[mid];
            int ops = windowSum - currSum;

            if(ops > k){
                i = mid + 1;
            }else{
                result = mid;
                j = mid - 1;
            }
         }
         return target_idx - result + 1;
    }

    int maxFrequency(vector<int>& nums, int k) {
        int n= nums.size();
        sort(begin(nums),end(nums));

        vector<long> prefixSum(n);
        prefixSum[0] = nums[0];
        for(int i=1;i<n;i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        int result = 0;

        for(int i=0;i<n;i++){
            result = max(result,findBest(i,k,nums,prefixSum));
        }

        return result;
    }
};

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        int l= 0;
        int result = 0;
        long currSum = 0;

        for(int r=0;r<n;r++){
            long target = nums[r];
            currSum += nums[r];
            // int opr = r-l+1;
            // Can use while instead 
            while((r-l+1)*target - currSum > k){
                currSum -= nums[l];
                l++;
            }

            result = max(result,r-l+1);
        }
        return result;
    }
};
