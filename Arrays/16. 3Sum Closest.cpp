class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int closestsum = 100000;
        sort(nums.begin(),nums.end());
        for(int k =0;k<n-2;k++){
            int i = k+1,j=n-1;
            while(i<j){
                int sum = nums[k] + nums[i] + nums[j];
                if(abs(target-sum)<abs(target-closestsum)){
                closestsum = sum;
                }

                if(sum < target){
                    i++;
                }else{
                    j--;
                }
            }
        }
        return closestsum;
    }
};

