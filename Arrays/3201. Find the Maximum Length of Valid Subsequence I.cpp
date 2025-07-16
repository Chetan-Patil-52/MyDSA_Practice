// FIrst approach which cam to my mind but didnt calculated parity of alternating ele - (Sliding Window) - 500+ TC passed
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;

        int i=0,j=1;
        while(j<n){
            int sum = nums[i]+nums[j];
            mp[sum%2]++;
            i++;
            j++;
        }

        int maxi = 0;
        for(auto it : mp){
            maxi = max(maxi,it.second);
        }

        return maxi+1;

    }
};

// Optimal approach 
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        int odds = 0;
        int evens = 0;
        int alternating = 1;

        for(auto &num : nums){
            if(num%2==0) evens++;
            else odds++;
        }

        int parity = nums[0]%2;
        // int length = 1;
        for(auto &num : nums){
            int currParity = num%2;
            if(currParity != parity){
                alternating++;
                parity = currParity;
            }
        }

        return max({alternating,odds,evens});
    }
};
