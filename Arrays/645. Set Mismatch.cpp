class Solution {
public:
//     Approach 1 - Using map
//     vector<int> findErrorNums(vector<int>& nums) {
//         int n=nums.size(),dup=0,miss=0;
//         map<int,int> mp;
//         for(int &x : nums){
//             mp[x]++;
//         }
//         for(int i=1;i<=n;i++){
//             if(mp.count(i)){
//                 if(mp[i] == 2){
//                     dup = i;
//                 }
//             }else{
//                 miss = i;
//             }
//         }
//         return {dup,miss};
//     }
// };


// Approach - 2 (Best Stat)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int miss=-1,dup=-1;
        for(int i=0;i<n;i++){
            int num = abs(nums[i]);
            if(nums[num-1] < 0){
                dup = num;
            }else{
                nums[num-1] *= (-1);
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i]>0){
                miss=(i+1);
                break;
            }
        }
        return {dup,miss};
    }
};
