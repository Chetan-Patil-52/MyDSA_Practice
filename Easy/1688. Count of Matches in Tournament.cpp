class Solution {
public:
    int numberOfMatches(int n) {
        // int matches = 0;
        // while(n>1){
        //     if(n%2!=0){
        //         matches++;
        //         n--;
        //     }else{
        //         matches += n/2;
        //         n /= 2;
        //     }
        // }
        // return matches;

      // Constant TC
        return n-1;
    }
};
