class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        int minPenalty = INT_MAX;
        int minHrs  = INT_MAX;
        for(int i=0;i<n;i++){
            int j = i-1;
            int penalty = 0;
            
            while(j>=0){
                if(customers[j]=='N'){
                    penalty++;
                }
                j--;
            }

            j = i;

            while(j<n){
                if(customers[j]=='Y'){
                    penalty++;
                }
                j++;
            }

            if(penalty < minPenalty){
                minPenalty = penalty;
                minHrs = i;
            }

        }
            // nth element 
            int nthHour = count(customers.begin(),customers.end(),'N');
            if(nthHour < minPenalty){
                minHrs = n;
            }
        
        return minHrs;
    }
};


class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();

        vector<int> prefixN(n+1,0);
        prefixN[0] = 0;
        vector<int> suffixY(n+1,0);
        suffixY[n]=0;

        for(int i=1;i<=n;i++){
            if(customers[i-1] == 'N'){
                prefixN[i] = prefixN[i-1]+1;
            }else{
                prefixN[i] = prefixN[i-1];
            }
        }

        for(int i=n-1;i>=0;i--){
            if(customers[i]=='Y'){
                suffixY[i] = suffixY[i+1]+1;
            }else{
                suffixY[i] = suffixY[i+1];
            }
        }

        int minPenalty = INT_MAX;
        int minHrs     = INT_MAX;

        for(int i=0;i<n+1;i++){
            int total = suffixY[i] + prefixN[i];

            if(total < minPenalty){
                minPenalty = total;
                minHrs = i;
            }


        }
        return minHrs;
    }
};




class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int penalty = count(begin(customers),end(customers),'Y');
        int minHrs = 0;

        int minPenalty = penalty;

        for(int i=0;i<n;i++){

            if(customers[i]=='Y'){
                penalty--;
            }else{
                penalty++;
            }

            if(penalty < minPenalty){
                minPenalty = penalty;
                minHrs = i+1;
            }
        }
        return minHrs;
    }
};
