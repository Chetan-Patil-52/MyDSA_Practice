class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int dir = 0;
        /*
        dir = 0 {l-r}
        dir = 1 {t-b}
        dir = 2 {r-l}
        dir = 3 {b-t}
        */
        vector<int> result;
        int down = m-1;
        int right = n-1;
        int top=0,left=0;

        while(top <= down && left <= right){
            if(dir==0){
                for(int i=left;i<=right;i++){
                    result.push_back(matrix[top][i]);
                }
                top++;
            }

            if(dir==1){
                for(int i=top;i<=down;i++){
                    result.push_back(matrix[i][right]);
                }
                right--;
            }

            if(dir==2){
                for(int i=right;i>=left;i--){
                    result.push_back(matrix[down][i]);
                }
                down--;
            }

            if(dir==3){
                for(int i=down;i>=top;i--){
                    result.push_back(matrix[i][left]);
                }
                left++;
            }

            dir = (dir+1)%4;
        }
        return result;
    }
};
