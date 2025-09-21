// First intution - (incorect)
class Solution {
public:

    bool check(string s){
        bool allSame =  all_of(begin(s),end(s),[&](char c){
            return c==s[0];
        });
        return allSame;
    }

    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        if(n<=1) return false;
        if(n%2==0){
            //even
            int mid = n/2;
            for(int i=0;i<mid;i++){
                if(s[i]!=s[mid+i]){
                    return false;
                }
            }
            return true;
        }else{
            //odd numbers
            // if all same true else false
            if(check(s)){
                return true;
            }else{
                return false;
            }
        }
    }
};
// Desired
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();

        for(int l=1;l<=n/2;l++){
            if(n%l==0){
                int times = n/l;
                string pattern = s.substr(0,l);
                string newStr = "";
                while(times--){
                    newStr += pattern;
                }

                if(newStr == s){
                    return true;
                }
            }
        }
        return false;
    }
};
