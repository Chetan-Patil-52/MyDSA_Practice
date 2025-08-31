class Solution {
public:

    bool check(vector<vector<char>>& board,int i,int j,int d){

        for(int a=0;a<9;a++){
            if(board[a][j]==d) return false;
            if(board[i][a]==d) return false;
        }

        int start_i = (i/3) * 3;
        int start_j = (j/3) * 3;
        for(int k=0;k<3;k++){
            for(int l=0;l<3;l++){
                if(board[start_i+k][start_j+l]==d)return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        int n = board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(board[i][j]=='.'){
                    for(int d='1';d<='9';d++){
                        if(check(board,i,j,d)){
                            board[i][j] = d;
                            if(solve(board)){
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
