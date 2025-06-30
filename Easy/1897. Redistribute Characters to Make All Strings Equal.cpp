class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        int array[26];
        for(auto &word : words){
            for(char &ch : word){
                array[ch-'a']++;
            }
        }

        for(int i=0;i<26;i++){
            if(array[i]%n != 0){
                return false;
            }
        }
        return true;
    }
};

// STL - 
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        int array[26];
        for(auto &word : words){
            for(char &ch : word){
                array[ch-'a']++;
            }
        }

        auto lambda = [&](int freq){
            return freq%n == 0;
        };
        
        return all_of(begin(array),end(array),lambda);
    }
};
