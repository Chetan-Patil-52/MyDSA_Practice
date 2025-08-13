// First thought
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<0) return false;
        if(n==1) return true;
        vector<int> pow3{'1','3','9','7'};
        string num = to_string(n);
        int len = num.length();
        if(n%3==0){
            for(int i=0;i<pow3.size();i++){
                if(num[len] == pow3[i]){
                    return true;
                }
            }
        }
        return false;
    }
};

// The one wih worked - Loop
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<0) return false;
        if(n==1) return true;
        int num = n;
        while(num%3==0 && (num/3) >0){
            num /= 3;
        }

        if(num==1) return true;
        return false;
    }
};

// Recursive
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        if(n==1) return true;
        if(n%3!=0) return false;

        return isPowerOfThree(n/3);
    }
};

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;


        double x = log10(n)/log10(3);

        return x == (int)x;
    }
};
