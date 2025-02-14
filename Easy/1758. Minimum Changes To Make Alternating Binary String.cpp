class Solution {
public:
    int minOperations(string s) {
        // Gready Doesent Works
        // int n = s.length();
        // int checker = s[0];
        // int count = 0;
        // for(int i = 1;i<n;i++){
        //     if(s[i] == checker){
        //         count++;
        //         if(s[i] == 0){
        //             s[i] = 1;
        //         }else{
        //             s[i] = 0;
        //         }
        //     }
        //     checker = s[i];
        // }
        // return count;

        int n = s.length();
        int starts_0 = 0,starts_1 = 0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(s[i] == '0'){
                    starts_1++;
                }else{
                    starts_0++;
                }
            }else{
                if(s[i]=='0'){
                    starts_0++;
                }else{
                    starts_1++;
                }
            }
        }
        return min(starts_1,starts_0);
    }
};
