// int t[100001][100001];
// is trying to allocate ~40 GB of stack memory, which is impossible on any competitive programming judge or local machine — hence the compiler hangs or crashes.

// Recurssion Memo (MLE)
class Solution {
public:
    int n;
    int t[100001][100001];
    int LIS(vector<int>& nums,int i,int P,int mod){

        if(i >= n) return 0;

        if(P != -1 && t[i][P] != -1){
            return t[i][P];
        }

        int take = 0;
        if(P==-1 || (nums[P] + nums[i])%2==mod){
            take = 1 + LIS(nums,i+1,i,mod);
        }

        int skip = LIS(nums,i+1,P,mod);

        if(P != -1){
            t[i][P] = max(take,skip);
        }

        return max(take,skip);
    }

    int maximumLength(vector<int>& nums) {
        n = nums.size();
        int maxLength = 0;

        memset(t,-1,sizeof(t));
        maxLength = max(maxLength,LIS(nums,0,-1,1));
        maxLength = max(maxLength,LIS(nums,0,-1,0));
        return maxLength;
    }
};

//Bottom up (TLE)
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp1(n,1);
        vector<int> dp0(n,1);

        int maxSub = 1;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int mod = (nums[j]+nums[i])%2;

                if(mod==1){
                    dp1[i] = max(dp1[i],dp1[j]+1);
                    maxSub = max(maxSub,dp1[i]);
                }
            }
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int mod = (nums[j]+nums[i])%2;

                if(mod==0){
                    dp0[i] = max(dp0[i],dp0[j]+1);
                    maxSub = max(maxSub,dp0[i]);
                }
            }
        }
        return maxSub;
    }
};

