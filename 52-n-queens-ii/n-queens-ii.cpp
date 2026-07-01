class Solution {
public:
    bool isSafe(int row,int col,int n,vector<bool> &rowcheck,vector<bool> &diag1check,vector<bool> &diag2check){
        if(rowcheck[row]==false && diag1check[row+col]==false && diag2check[n-1+row-col]==false){
            rowcheck[row]=true;
            diag1check[row+col]=true;
            diag2check[row-col+n-1]=true;
            return true;
        }
        return false;
    }
    void solve(int col, int &ans,int n, vector<bool> &rowcheck,vector<bool> &diag1check,vector<bool> &diag2check){
        if(col==n){
            ans++;
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,n,rowcheck,diag1check,diag2check)){
                solve(col+1,ans,n, rowcheck,diag1check,diag2check);
                rowcheck[row]=false;
                diag1check[col+row]=false;
                diag2check[n-1-col+row]=false;
            }
        }
    }
    int totalNQueens(int n) {
        if(n==0 || n==2) return 0;
        if(n==1) return 1;
        vector<bool> rowcheck(n,false);
        vector<bool> diag1check(2*n,false);
        vector<bool> diag2check(2*n,false);
        int ans=0;
        solve(0,ans,n, rowcheck,diag1check,diag2check);
        return ans;
    }
};