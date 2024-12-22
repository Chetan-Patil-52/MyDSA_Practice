class Solution {
public:
    char findTheDifference(string s, string t) {
        // unordered_map<char ,int>mp;

        // for(char &ch : s){
        //     mp[ch]++;
        // }

        // for(char &ch : t){
        //     mp[ch]--;

        //     if(mp[ch] < 0){
        //         return ch;
        //     }
        // }
        // return 'chetan';


    //     int sum = 0;
    //     // int sum2 = 0;


    //     for(char &ch : t){
    //         sum += ch;
    //     }

    //     for(char &ch : s){
    //         sum -= ch;
    //     }
    //     // int diff = sum2-sum1;
    //     return (char)(sum);

        int XOR = 0;
        for(char &ch : s){
            XOR ^= ch;
        }

        for(char &ch : t){
            XOR ^= ch;
        }

        return (char)XOR;

    }
};
