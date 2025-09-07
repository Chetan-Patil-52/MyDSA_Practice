class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        int neg = -1;
        int pos = 1;
        if(n%2!=0) result.push_back(0);
        for(int i=0;i<n/2;i++){
            result.push_back(neg);
            result.push_back(pos);
            neg--;
            pos++;
        }
        sort(result.begin(),result.end());
        return result;
    }
};

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result(n);
        int neg = -1;
        int j = n-1;
        int pos = 1;
        if(n%2!=0) result[n/2]=0;
        for(int i=0;i<n/2;i++){
            // result.push_back(neg);
            // result.push_back(pos);
            result[i] = pos;
            result[j-i] = neg;

            neg--;
            pos++;
        }
        // sort(result.begin(),result.end());
        return result;
    }
};
