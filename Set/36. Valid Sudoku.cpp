class Solution {
public:
    bool check(vector<vector<char>>& board,int sr,int er,int sc,int ec){
        unordered_set<char> st;
        for(int i=sr;i<=er;i++){
            for(int j=sc;j<=ec;j++){
                char ch=board[i][j];
                if(ch=='.') continue;
                if(st.find(ch) != st.end()) return false;
                st.insert(ch);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        // Check Rows
        int n = board.size();
        for(int r=0;r<n;r++){
            unordered_set<char> st;
            for(int c=0;c<n;c++){
                char ch = board[r][c];
                if(ch == '.') continue;
                if(st.find(ch) != st.end()) return false;
                st.insert(ch);
            }
        }
        // Check Cols
        for(int c=0;c<n;c++){
            unordered_set<char> st;
            for(int r=0;r<n;r++){
                char ch = board[r][c];
                if(ch=='.') continue;
                if(st.find(ch) != st.end()) return false;
                st.insert(ch);
            }
        }
        // Check 3x3
        for(int sr=0;sr<n;sr+=3){
            int er = sr+2;
            for(int sc=0;sc<n;sc+=3){
                int ec = sc+2;

                if(!check(board,sr,er,sc,ec)){
                    return false;
                }
            }
        }

        return true;
    }
};


// Optimal - (SMART)

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        unordered_set<string> st;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                char ch = board[i][j];
                if(ch=='.') continue;
                
                string row = string(1,board[i][j]) + "_ROW_" + to_string(i);
                string col = string(1,board[i][j]) + "_COL_" + to_string(j);
                string box = string(1,board[i][j]) + "_BOX_" + to_string(i/3) +"_" + to_string(j/3);


                if(st.count(row) || st.count(col) || st.count(box)) return false;

                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }
        return true;
    }
};
