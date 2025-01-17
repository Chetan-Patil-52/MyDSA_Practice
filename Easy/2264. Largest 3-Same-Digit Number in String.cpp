class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.length();
        int count = 1;
        string result = "";
        int maxi = -1;
        bool flag = false;
        for(int i=1;i<n;i++){
            if(num[i] != num[i-1]){
                count = 0;
            }
            count++;
            if(count==3){
                maxi = max(maxi,num[i] - '0');
                count = 0;
                flag = true;
            }
        }

        for(int i=0;i<3;i++){
            if(flag){
                result += maxi + '0';
            }else{
                break;
            }
        }

        return result;
    }
};
