class Solution {
public:

    bool isVowel(char ch){
        if(ch=='a' || ch=='e'|| ch=='i' || ch=='o' || ch=='u'){
            return true;
        }
        return false;
    }

    bool doesAliceWin(string s) {
        int cnt = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                cnt++;
            }
        }
        if(cnt==0) return false;
        else return true;
    }
};

// Using STL's

class Solution {
public:
    bool doesAliceWin(string s) {
        auto lambda = [] (char ch){
            return string("aeiou").find(ch) != string::npos;
        };
        return any_of(begin(s),end(s),lambda);
    }
};

class Solution {
public:
    bool doesAliceWin(string s) {
        auto lambda = [] (char ch){
            return ch=='a' || ch=='e'|| ch=='i' || ch=='o' || ch=='u';
        };
        return any_of(begin(s),end(s),lambda);
    }
};
