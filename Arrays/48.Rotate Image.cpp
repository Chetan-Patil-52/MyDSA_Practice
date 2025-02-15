class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(); // rows
        int m = n; // n x n matrix

        // Transpose
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i = 0;i<m;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
