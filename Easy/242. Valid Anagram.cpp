class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n!=m){
            return false;
        }
        unordered_map<char ,int> mp;
        for(char ch : s){
            mp[ch]++;
        }
        for(char ch : t){
            mp[ch]--;
            if(mp[ch] < 0){
                return false;
            }
        }
        return true;
    }
};

// Using Sort 
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n!=m){
            return false;
        }
        sort(begin(s),end(s));
        sort(begin(t),end(t));

        return s==t;
    }
};

// Using vector & Lambda function
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n!=m){
            return false;
        }
        
        vector<int> count(26,0);
        for(char ch : s){
            count[ch-'a']++;
        }
        for(char ch : t){
            count[ch - 'a']--;
        }

        bool allZeros = all_of(begin(count),end(count),[](int element){
            return element == 0;
        });
        return allZeros;
    }
};
