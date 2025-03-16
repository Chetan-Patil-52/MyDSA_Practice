// Code 

// Brute force : O(n) -  workded without BS
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        
        int first = -1;
        int last = -1;

        for(int i=0;i<n;i++){
            if(nums[i] == target){
                if(first == -1) first = i;
                last = i;
            }
        }
        return {first,last};
    }
};

// Using Binary Search 
class Solution {
public:
    int findLeftMost(vector<int>& nums,int target,int n){
        int l=0;int r=n-1;
        int left_most = -1;

        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                left_most = mid;
                r = mid -1;
            }else if(nums[mid] < target){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return left_most;
    }

    int findRightMost(vector<int>& nums,int target,int n){
        int l=0;int r=n-1;
        int right_most = -1;

        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                right_most = mid;
                l = mid+1;
            }else if(nums[mid] < target){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return right_most;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n= nums.size();
        int left_most = findLeftMost(nums,target,n);
        int right_most = findRightMost(nums,target,n);

        return {left_most,right_most};
    }
};
