class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        // Length can be diffrent 
        // if(word1.size() != word2.size()){
        //     return false;
        // }
        int idx = 0;
        unordered_map<int ,char> mp;
        for(string str : word1){
            for(char ch : str){
                mp[idx] = ch;
                idx++;
            }
        }
        int i=0;
        for(string str : word2){
            for(char ch : str){
                if(mp[i] != ch){
                    return false;
                }
                i++;
            }
        }
        return i==idx;
    }
};

// Optimal 
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
      // Optimal Approach 
        string str1 = "";
        for(string s : word1){
            str1 += s;
        }

        string str2 = "";
        for(string s : word2){
            str2 += s;
        }
        return str1==str2;
    }
};
