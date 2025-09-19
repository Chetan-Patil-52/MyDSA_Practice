class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int stream = 1;
        stack<int> st;
        int m = target.size();
        vector<string> res;
        int i=0;
        while(i<m && stream <= n){
            res.push_back("Push");
            if(target[i]==stream){
                i++;
            }else{
                // stream++;
                res.push_back("Pop");
            }
            stream++;
        }
        return res;
    }
};

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int> st;
        vector<string> ans;
        int j=0;
        int i=1;
        int size = target.size();
        while(i<=n){
            ans.push_back("Push");
            if(st.size()==size){
                break;
            }
            else if(i==target[j]){
                j++;
                st.push(i);
                // ans.push_back("Push");
            }else{
                // ans.push_back("Push");
                ans.push_back("Pop");
            }
            i++;
        }
        return ans;
    }
};
