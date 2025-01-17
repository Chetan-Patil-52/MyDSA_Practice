// class Solution {
// public:
//     int maxProductDifference(vector<int>& nums) {
//         int n=nums.size();sort(nums.begin(),nums.end());return ((nums[n-1]*nums[n-2]) - (nums[0] * nums[1]));
//     }
// };

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n=nums.size();
        int largest=INT_MIN,sLargest=INT_MIN;
        int smallest=INT_MAX,sSmallest=INT_MAX;
        for(int &num : nums){
            if(num > largest){
                sLargest = largest;
                largest = num;
            }else{
                sLargest = max(sLargest,num);
            }
        }

        for(int &num : nums){
            if(num < smallest){
                sSmallest = smallest;
                smallest = num;
            }else{
                sSmallest = min(sSmallest,num);
            }
        }
        return (largest*sLargest) - (smallest*sSmallest);
    }
};
