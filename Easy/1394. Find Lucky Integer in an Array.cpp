
// TC : O(2N)
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }

        int maxFreq = -1;
        for(auto it : mp){
            if(it.first==it.second){
                maxFreq = max(maxFreq,it.second);
            }
        }
        return maxFreq;
    }
};


// TC : nlogn
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        sort(begin(arr),end(arr));
        int maxFreq = -1;
        int currFreq = 1;
        for(int i=1;i<n;i++){
            if(arr[i]!=arr[i-1]){
                // if(arr[n-1] = arr[n-2]){
                //     currFreq++;
                // }
                if(arr[i-1]==currFreq){
                    maxFreq = max(maxFreq,currFreq);
                }
                currFreq = 1;
            }else{
                currFreq++;
            }
        }
        if(arr[n-1] == currFreq) {
            maxFreq = max(maxFreq, currFreq);
        }
        return maxFreq;
    }
};
