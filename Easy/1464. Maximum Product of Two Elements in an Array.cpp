// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(),nums.end());

//         int result = (nums[n-1] - 1) * (nums[n-2] - 1);
//         return result;
//     }
// };

// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();
//         int currMax = nums[0];
//         int result =0;
//         for(int i=1;i<n;i++){
//             result = max(result,(nums[i]-1) * (currMax -1));
//             currMax = max(currMax,nums[i]);
//         }
//         return result;
//     }
// };

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int largest=0,secondL=0;
        for(int i=0;i<n;i++){
            if(nums[i]>largest){
                secondL = largest;
                largest = nums[i];
            }else if(nums[i]>secondL){
                secondL = nums[i];
            }
        }
        return (secondL-1) * (largest-1);
    }
};
