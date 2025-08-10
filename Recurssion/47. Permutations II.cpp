// App-1
class Solution {
public: 
    int n;
    vector<vector<int>> result;
    set<vector<int>> st;
    void solve(int idx,vector<int>& nums){
        if(idx == n){
            if(st.find(nums) == st.end()){
                result.push_back(nums);
                st.insert(nums);
            }
            return;
        }

        for(int i=idx;i<n;i++){
            swap(nums[i],nums[idx]);
            solve(idx+1,nums);
            swap(nums[i],nums[idx]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n= nums.size();
        solve(0,nums);
        return result;
    }
};

// similar set of INT 
class Solution {
public: 
    int n;
    vector<vector<int>> result;
    
    void solve(int idx,vector<int>& nums){

        unordered_set<int> st;

        if(idx == n){
            result.push_back(nums);
            // st.insert(nums);
            return;
        }

        for(int i=idx;i<n;i++){

            if(st.find(nums[i]) != st.end()){
                continue;
            }
            st.insert(nums[i]);
            swap(nums[i],nums[idx]);
            solve(idx+1,nums);
            swap(nums[i],nums[idx]);
            // st.erase(nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n= nums.size();
        solve(0,nums);
        return result;
    }
};

// Using Map
class Solution {
public:
    int n;
    vector<vector<int>> result;

    void solve(unordered_map<int,int>& mp,vector<int>& nums){

        if(nums.size()==n){
            result.push_back(nums);
            return;
        }

        for(auto& [num , count] : mp){
            if(count==0) continue;


            nums.push_back(num);
            mp[num]--;

            solve(mp,nums);

            nums.pop_back();
            mp[num]++;
        }

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();

        unordered_map<int,int> mp;

        for(int num : nums){
            mp[num]++;
        }

        vector<int> temp;

        solve(mp,temp);
        return result;
    }
};
