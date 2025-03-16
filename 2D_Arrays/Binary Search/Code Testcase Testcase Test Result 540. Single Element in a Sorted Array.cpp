// using XOR
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int xOR = 0;
        for(int i=0;i<n;i++){
            xOR ^= nums[i];
        }
        return xOR;
    }
};

