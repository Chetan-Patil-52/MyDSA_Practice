// Brute - first App
class Solution {
public:
    vector<string> result;
    int len;
    void solve(unordered_map<int,int>& mp,int n,string temp){

        // string temp = "";
        if(temp.length()==len){
            result.push_back(temp);
            return;
        }

        for(auto [num, count] : mp){
            if(count ==0) continue;

            // temp += to_string(num);
            mp[num]--;
            solve(mp,n,temp + to_string(num));
            // temp.pop_back();
            mp[num]++;

        }
    }


    bool powerOf2(int number){
        return (number&(number-1))==0;
    }

    bool reorderedPowerOf2(int n) {
        if(n==1) return true;
        unordered_map<int,int> mp;
        int num = n;
        while(num>0){
            int rem = num%10;
            mp[rem]++;
            num/=10;
            len++;
        }

        solve(mp,n,"");

        //for() ill interate orver string result and check any one prmutation is power of 2 or else flse

        for(string permutation : result){
            if(permutation[0] == '0') continue;
            int number = stoi(permutation);
            if(powerOf2(number)){
                return true;
            }
        }
        return false;
    }
};
