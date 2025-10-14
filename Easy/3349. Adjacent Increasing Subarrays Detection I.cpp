// Initial Idea/ Thought : 
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> incStart;
        for(int i=0;i<=n-k;i++){
            bool flag = true;
            for(int j=i+1;j<i+k;j++){
                if(nums[j]<=nums[j-1]){
                    flag = false;
                }
            }
            if(flag){
                incStart.push_back(i);
            }
        }
        sort(begin(incStart),end(incStart));
        for(int i=1;i<incStart.size();i++){
            if(incStart[i]-incStart[i-1] >= k){
                return true;
            }
        }
        return false;
    }
};

// Optimal 
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int cl = 1;
        int pl = 0;
        int result = 0;
        for(int i=1;i<n;i++){
            if(nums[i] > nums[i-1]){
                cl++;
            }else{
                pl = cl;
                cl = 1;
            }
            result = max(result,max(cl/2,min(pl,cl)));
        }
        return result;
    }
};
