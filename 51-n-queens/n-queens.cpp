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
    bool isSafe(int row, int col, vector<vector<int>> &board,int n,vector<bool> &rowCheck,vector<bool> &diag1Check,vector<bool> &diag2Check){
        int x=row;
        int y=col;
        if(rowCheck[x]==false && diag1Check[x+y]==false && diag2Check[x-y+n-1]==false){
            rowCheck[x]=true;
            diag1Check[x+y]=true;
            diag2Check[x-y+n-1]=true;
            return true;
        }
        return false;
    }
    void solve(int col,vector<vector<string>>&ans, vector<vector<int>> &board,int n,vector<bool> &rowCheck,vector<bool> &diag1Check,vector<bool> &diag2Check){
        if(col==n){
            addSolution(ans,board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n,rowCheck,diag1Check,diag2Check)){
                board[row][col]=1;
                solve(col+1,ans,board,n,rowCheck,diag1Check,diag2Check);
                board[row][col]=0;
                rowCheck[row] = false;
                diag1Check[row + col] = false;
                diag2Check[n - 1 + row - col] = false;
            }
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        if(n==1) return {{"Q"}};
        if(n==2) return {};
        vector<bool> rowCheck(n, false);
        vector<bool> diag1Check(2 * n, false);
        vector<bool> diag2Check(2 * n, false);
        vector<vector<string>> ans;
        vector<vector<int>> board(n,vector<int>(n,0));
        solve(0,ans,board,n,rowCheck,diag1Check,diag2Check);
        return ans;
    }
};