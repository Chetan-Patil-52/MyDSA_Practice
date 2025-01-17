class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(string &word : words)                {
            mp[word]++;
        }
        vector<pair<string,int>> vec;
        for(auto &it : mp){
            vec.push_back({it.first,it.second});
        }

        auto lambda = [](pair<string,int>& p1,pair<string,int>& p2){
            if(p1.second==p2.second){
                return p1.first < p2.first;
            }
            return p1.second>p2.second;
        };

        sort(begin(vec),end(vec),lambda);

        int i = 0;
        vector<string> result(k);
        while(i<k){
            result[i] = vec[i].first;
            i++;
        }

        return result;
    }
};
