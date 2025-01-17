// class Solution {
// public:
//     int countCharacters(vector<string>& words, string chars) {
//         int m = words.size();
//         int n = chars.length();
//         vector<int> wordCount(26);
//         for(char ch : chars){
//             wordCount[ch-'a']++;
//         }
//         int count = 0;
//         for(string str : words){
//             vector<int> charCount(26);
//             int len = str.length();
//             bool flag = true;
//             for(char ch : str){
//                 charCount[ch-'a']++;
//                 if(charCount[ch-'a'] > wordCount[ch-'a']){
//                     flag = false;
//                     break;
//                 }
//             }
//             if(flag){
//                 count += len;
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int m = words.size();
        int n = chars.length();
        unordered_map<char,int> wordCount(n);
        for(char ch : chars){
            wordCount[ch]++;
        }
        int count = 0;
        for(string str : words){

            unordered_map<char,int> charCount;
            int len = str.length();
            bool flag = true;
            for(char ch : str){
                charCount[ch]++;
                if(charCount[ch] > wordCount[ch]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                count += len;
            }
        }
        return count;
    }
};
