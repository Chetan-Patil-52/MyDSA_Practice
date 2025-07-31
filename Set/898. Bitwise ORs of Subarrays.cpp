// Brute force TLE 
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n= arr.size();
        unordered_set<long long> st;
        for(int num : arr){
            st.insert(num);
        }

        for(int i=0;i<n;i++){
            long long res = arr[i];
            for(int j=i+1;j<n;j++){
                if(j<n-1 && arr[i]==arr[j]) j++;
                res |= arr[j];
                if(st.find(res) == st.end()){
                    st.insert(res);
                }
            }
        }
        return st.size();
    }
};

// Optimal O(n*32) 3 sets
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        unordered_set<int> prev;
        unordered_set<int> curr;

        for(int i=0;i<arr.size();i++){

            for(int x : prev){
                curr.insert(x | arr[i]);
                result.insert(x | arr[i]);
            }

            curr.insert(arr[i]);
            result.insert(arr[i]);

            prev = curr;
            curr.clear();
        }
        return result.size();
    }
};
