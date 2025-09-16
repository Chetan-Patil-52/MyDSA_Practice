// Brute 
class Solution {
public:
    long long countSubstrings(string s, char c) {
        int n = s.length();
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i]==c){
                for(int j=i;j<n;j++){
                    if(s[j]==c){
                        cnt++;
                    }
                }  
            }   
        }
        return cnt;
    }
};

class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long cnt = 0;
        long long subStr = 0;
        for(char ch : s){
            if(ch==c){
                subStr += 1 + (cnt);
                cnt++;
            }
        }
        return subStr;
    }
};


class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long cnt = 0;
        // long long subStr = 0;
        for(char ch : s){
            if(ch==c){
                // subStr += 1 + (cnt);
                cnt++;
            }
        }
        return (cnt*(cnt-1)/2) +cnt;
    }
};

