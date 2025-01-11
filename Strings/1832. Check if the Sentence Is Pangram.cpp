class Solution {
public:
    bool checkIfPangram(string sentence) {
        // Approach -1
        // vector<int> seen(26,0);

        // for(char ch : sentence){
        //     int idx = ch - 'a';
        //     seen[idx]++;
        // }

        // for(int &count : seen){
        //     if(count==0){
        //         return false;
        //     }
        // }
        // return true;

        // Approach -2
        // unordered_set<char> seen;
        // // Check if char is btw the elem 
        // for(char &ch : sentence){
        //     if(ch >= 'a' && ch <= 'z'){
        //         seen.insert(ch);
        //     }
        // }
        // return seen.size() == 26;

        // Approach -3
        vector<int> seen(26,0);
        int count = 0;
        for(char ch : sentence){
            int idx = ch - 'a';

            if(seen[idx]==0){
                seen[idx]++;
                count++;
            }
        }
        return count==26;
    }
};
