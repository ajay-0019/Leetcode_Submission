class Solution {
public:
    void addSolution(vector<vector<string>>&ans, vector<vector<int>> &board){
        vector<string> temp;
        for(int i=0;i<board.size();i++){
            string str="";
            for(int j=0;j<board.size();j++){
                if(board[i][j]==1){
                    str.push_back('Q');
                }else{
                    str.push_back('.');
                }
            }
            temp.push_back(str);
        }
        ans.push_back(temp);
    }
    bool isSafe(int row, int col, vector<vector<int>> &board,int n){
        int x=row;
        int y=col;
        while(y>=0){
            if(board[x][y]==1){
                return false;
            }
            y--;
        }
        x=row;
        y=col;
        while(x>=0 && y>=0){
            if(board[x][y]==1){
                return false;
            }
            x--;
            y--;
        }
        x=row;
        y=col;
        while(x<n && y>=0){
            if(board[x][y]==1){
                return false;
            }
            x++;
            y--;
        }
        return true;
    }
    void solve(int col,vector<vector<string>>&ans, vector<vector<int>> &board,int n){
        if(col==n){
            addSolution(ans,board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]=1;
                solve(col+1,ans,board,n);
                board[row][col]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        if(n==1) return {{"Q"}};
        if(n==2) return {};
        vector<vector<string>> ans;
        vector<vector<int>> board(n,vector<int>(n,0));
        solve(0,ans,board,n);
        return ans;
    }
};