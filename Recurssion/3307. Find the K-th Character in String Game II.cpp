class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        // Can be solved using recurssion.

        // Base condition
        if(k==1) return 'a';

        int n= operations.size();
        long long len = 1;
        long long new_k = -1;
        int oper_type = -1;


        for(int i=0;i<n;i++){
            len *= 2;
            if(len >= k){
                new_k = k- len/2;
                oper_type = operations[i];
                break;
            }
        }

        char ch = kthCharacter(new_k, operations);

        if(oper_type == 0){
            return ch;
        }

        return ch == 'z' ? 'a' : ch+1;

    }
};
