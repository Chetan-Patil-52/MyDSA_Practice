class Solution {
public:

    bool isVowel(char ch){
        if(ch=='a' || ch=='e'|| ch=='i' || ch=='o' || ch=='u'){
            return true;
        }
        return false;
    }

    int maxFreqSum(string s) {
        int n = s.length();
        int maxV = 0;
        int maxC = 0;
        vector<int> cnt(26,0);
        for(char ch : s){
            cnt[ch-'a']++;
        }
        for(char ch : s){
            if(isVowel(ch)){
                maxV = max(maxV,cnt[ch-'a']);
            }else{
                maxC = max(maxC,cnt[ch-'a']);
            }
        }
        return maxV + maxC;
    }
};
