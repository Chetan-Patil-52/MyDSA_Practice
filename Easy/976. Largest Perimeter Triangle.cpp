// TLE 
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j] > nums[k] && nums[i]+nums[k] > nums[j] && nums[k]+nums[j] > nums[i] ){
                        int sum = nums[i]+nums[k]+nums[j];
                        maxi = max(sum,maxi);
                    }
                }
            }
        }
        return maxi;
    }
};

// Accepted
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        sort(begin(nums),end(nums));
        for(int k=n-1;k>=0;k--){
            int i=0;
            int j = k-1;
            while(i<j){
                if(nums[i]+nums[j] > nums[k]){
                    int sum = nums[i]+nums[j] + nums[k];
                    maxi = max(maxi,sum);
                }
                i++;
            }
        }
        return maxi;
    }
};

// O(n)
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n = nums.size();
        for(int i=n-3;i>=0;i--){
            if(nums[i]+nums[i+1] > nums[i+2]){
                return nums[i]+nums[i+1] + nums[i+2];
            }
        }
        return 0;
    }
};



//
