class Solution {
public:

    string generate(string& word){
        int arr[26] = {0};
        for(char &ch : word){
            arr[ch-'a']++;
        }
        string new_word="";

        for(int i = 0;i<26;i++){
            int freq = arr[i];
            if(freq>0){
                new_word += string(freq,i+'a');
            }
        }
        return new_word;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Approach - 1 
    //     int n = strs.size();
    //     vector<vector<string>> result;
    //     unordered_map<string , vector<string>> mp;

    //     for(int i = 0;i<n;i++){
    //         string temp = strs[i];
    //         sort(begin(temp),end(temp));
    //         mp[temp].push_back(strs[i]);
    //     }
    //     for(auto it : mp){
    //         result.push_back(it.second);
    //     }
    //     return result;

        int n = strs.size();
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp;
        for(int i=0;i<n;i++){
            string word = strs[i];
            string new_word = generate(word);
            mp[new_word].push_back(word);
        }
        for(auto &it : mp){
            result.push_back(it.second);
        }
        return result;
    }
};
