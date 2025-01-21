class Solution {
public:

    int countOverLaps(vector<vector<int>>& A,vector<vector<int>>& B,int rowOff,int colOff){
        int n = A.size();
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i+rowOff < 0 || j + colOff < 0 || i+rowOff >= n || j+colOff >= n){
                    continue;
                }

                count += A[i][j]*B[i+rowOff][j+colOff];
            }
        }
        return count;
    }

    int largestOverlap(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size();
        int maxOverLap = 0;

        for(int rowOff = -n+1;rowOff<n;rowOff++){
            for(int colOff = -n+1;colOff<n;colOff++){
                maxOverLap = max(maxOverLap, countOverLaps(a,b,rowOff,colOff));
            }
        }
        return maxOverLap;
    }
};
