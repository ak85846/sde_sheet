class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                //if empty
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(valid(board,i,j,c)){
                            board[i][j]=c;
                        
                        if(solve(board)==true)
                            return true;
                        else
                            board[i][j]='.';
                    }
                    }
                    return false;
                }
            }
        }
        return true;//in last when there is no empty space
    }
    
    bool valid(vector<vector<char>>& board,int row,int col,char c){
        for(int i=0;i<9;i++){
            // row check
            if(board[row][i]==c)
                return false;
            //col check
            if(board[i][col]==c)
                return false;
            //3*3 grid check
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
                return false;
        }
        return true;
    }
};