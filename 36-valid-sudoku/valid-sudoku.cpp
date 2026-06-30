class Solution {
public:
    bool solve(int row,int col,vector<vector<char>> & board){
        char check = board[row][col];
        for(int i=0;i<9;i++){
            if(i==col){
                continue;
            }else if(check==board[row][i]){
                return false;
            }
        }
        for(int i=0;i<9;i++){
            if(i==row){
                continue;
            }else if(check==board[i][col]){
                return false;
            }
        }
        int cols=0;
        int rows=0;
        if(col<=2 && row<=2){
            cols=0;
            rows=0;
        }else if((col>2 && col<=5) && (row<=2)){
            cols=3;
            rows=0;
        }else if((col>5)&&(row<=2)){
            cols=6;
            rows=0;
        }else if(row>2 && row<=5){
            if(col<=2){
                cols=0;
                rows=3;
            }else if(col>2 && col<=5){
                cols=3;
                rows=3;
            }else{
                cols=6;
                rows=3;
            }
        }else{
            if(col<=2){
                cols=0;
                rows=6;
            }else if(col>2 && col<=5){
                cols=3;
                rows=6;
            }else{
                rows=6;
                cols=6;
            }
        }
        for(int i=rows;i<=rows+2;i++){
            for(int j=cols;j<=cols+2;j++){
                if(i==row && j==col){
                    continue;
                }else if(check==board[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                if(board[i][j]!='.' && !solve(i,j,board)){
                    return false;
                }
            }
        }
        return true;
    }
};