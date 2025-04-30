class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            int check = to_string(nums[i]).length();
            if(check%2==0){
                cnt++;
            }
        }
        return cnt;
    }
};
