class Solution {
public:
    int M = 1e9+7;

    int rev(int num){
        //321
        int reminder = 0;
        int reverse = 0;
        while(num){
            // reminder = num %10;
            // reverse = (reverse * 10) + reminder;
            // num /= 10;
            reverse =(reverse * 10) +  num%10;
            num /= 10;
            // pow *=10;.;
        }
        return reverse;
    }

    int countNicePairs(vector<int>& nums) {
        int n = nums.size();

        for(int i=0;i<n;i++){
            nums[i] = nums[i] - rev(nums[i]);
        }

        unordered_map<int,int> mp;
        int result = 0;
        for(int i=0;i<n;i++){
            result = (result + mp[nums[i]]) % M;
            mp[nums[i]]++;
        }
        return result;
    }
};
