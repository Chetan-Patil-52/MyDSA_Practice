// incplace in O(n) or O(2n)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> result;
        int arr[10] = {0};
        int n = nums.size();
        for(int i=0;i<n;i++){
            arr[nums[i]]++;
        }
        int count = 0;
        for(int i=0;i<10;i++){
            int freq = arr[i];
            for(int j=0;j<freq;j++){
                nums[count] = i;
                count++;
            }
            
        }
        // return result;
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i=0,j=0;
        int k=n-1;
        while(j<=k){
            if(nums[j]==1){
                j++;
            }else if(nums[j] == 2){
                swap(nums[j],nums[k]);
                k--;
            }else{// nums[j] == 0
                swap(nums[j],nums[i]);
                i++;
                j++;
            }
        }
    }
};
