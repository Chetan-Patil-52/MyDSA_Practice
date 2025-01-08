class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int gola_idx = -1;

        // Find the first element from the end which is smaller than its next element
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                gola_idx = i - 1;  // Store the index of the element that needs to be swapped
                break;
            }
        }

        if (gola_idx != -1) {
            // Find the smallest element greater than nums[gola_idx] to swap with
            int swap_idx = n - 1;
            for (int j = n - 1; j > gola_idx; j--) {
                if (nums[j] > nums[gola_idx]) {
                    swap_idx = j;
                    break;
                }
            }

            // Swap the elements at gola_idx and swap_idx
            swap(nums[gola_idx], nums[swap_idx]);
        }

        // Reverse the subarray after gola_idx to get the next smallest lexicographical permutation
        reverse(nums.begin() + gola_idx + 1, nums.end());
    }
};
