// App-1
 class Solution {
public:
    int n;
    vector<vector<int>> result;
    unordered_set<int> st;
    void solve(vector<int>& nums,vector<int>& temp){
        if(temp.size()==n){
            result.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++){
            int num = nums[i];
            if(st.find(num) == st.end()){

                temp.push_back(num);
                st.insert(num);

                solve(nums,temp);

                temp.pop_back();
                st.erase(num);
            }


        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<int> temp;

        solve(nums,temp);

        return result;
    }
};
// App -2

class Solution {
public:
    int n;
    vector<vector<int>> result;

    void solve(int idx,vector<int>& nums){
        if(idx == n){
            result.push_back(nums);
            return;
        }

        for(int i=idx;i<n;i++){

            swap(nums[i],nums[idx]);
            solve(idx+1,nums);
            swap(nums[i],nums[idx]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        solve(0,nums);
        return result;
    }
};

// 
