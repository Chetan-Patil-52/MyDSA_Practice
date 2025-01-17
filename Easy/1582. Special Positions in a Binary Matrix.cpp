// class Solution {
// public:
//     int numSpecial(vector<vector<int>>& mat) {
//         int m = mat.size();
//         int n = mat[0].size();
//         int result = 0;
//         for(int row=0;row<m;row++){
//             for(int col=0;col<n;col++){
//                 if(mat[row][col]==0) continue;
//                 if(mat[row][col]==1){
//                     bool special = true;
//                     // Check the row
//                     for(int r=0;r<m;r++){
//                         if(r!=row && mat[r][col]==1){
//                             special = false;
//                             break;
//                         }
//                     }
//                     // Check the row
//                     for(int c=0;c<n;c++){
//                         if(c!=col && mat[row][c]==1){
//                             special = false;
//                             break;
//                         }
//                     }

//                     if(special){
//                         result++;
//                     }
//                 }
//             }
//         }
//         return result;
       
//     }
// };

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int result = 0;
        vector<int> rowCount(m),colCount(n);
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(mat[row][col]==1){
                    rowCount[row]++;
                    colCount[col]++;
                }
            }
        }

        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(mat[row][col]==0) continue;
                if(rowCount[row] == 1 && colCount[col]==1){{
                    result++;
                }
                    
                }
            }
        }
        return result;
    }
};
