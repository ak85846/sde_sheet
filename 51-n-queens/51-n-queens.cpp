class Solution {
public:
    bool is_safe(int row,int col,int n,vector<string>board){
        int dummyrow=row;
        int dummycol=col;
        //for diagonal upper
        while(row>=0 && col>=0){
            if(board[row][col]=='Q')
                return false;
            row--;
            col--;
        }
        //for straight left
        row=dummyrow;
        col=dummycol;
        while(col>=0){
            if(board[row][col]=='Q')
                return false;
            col--;
        }
        //for diagonal lower
        row=dummyrow;
        col=dummycol;
        while(row<n && col>=0){
            if(board[row][col]=='Q')
                return false;
            row++;
            col--;
        }
        return true;
    }
    void nqueen(int col,int n,vector<string>&board,vector<vector<string>>&res){
        if(col==n){
            res.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(is_safe(row,col,n,board)){
                board[row][col]='Q';
                nqueen(col+1,n,board,res);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n);
        vector<vector<string>>res;
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        nqueen(0,n,board,res);
        return res;
    }
};