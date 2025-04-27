class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        // Forloop doesn't works as we need to find subarray not substring
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         for(int k=j+1;k<n;k++){
        //             if((nums[i] + nums[k]) * 2 == nums[j]){
        //                 cnt++;
        //             }
        //         }
        //     }
        // }
        int i=0,j=1,k=2;
        // int cnt = 0;
        while(k<=n-1){
            if((nums[i]+nums[k]) * 2==nums[j]){
                cnt++;
            }
            i++;
            j++;
            k++;
        }
        return cnt;
    }
};
