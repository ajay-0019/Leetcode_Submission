class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==1){
            return matrix[0];
        }
        vector<int> ans;
        int rowB=matrix.size()-1;
        int rowT=0;
        int colL=0;
        int colR=matrix[0].size()-1;
        int i=colL;
        while(rowT <= rowB && colL <= colR){
            i=colL;
            while(i <= colR){
                ans.push_back(matrix[rowT][i]);
                i++;
            }
            rowT++;
            i=rowT;
            while(i <= rowB){
                ans.push_back(matrix[i][colR]);
                i++;
            }
            colR--;
            i=colR;
            if (rowT <= rowB) {
                while(i-colL>=0){
                    ans.push_back(matrix[rowB][i]);
                    i--;
                }
            }
            rowB--;
            i=rowB;
            if (colL <= colR) {
                while(i-rowT>=0){
                    ans.push_back(matrix[i][colL]);
                    i--;
                }
            }
            
            colL++;
        }
        return ans;
    }
};