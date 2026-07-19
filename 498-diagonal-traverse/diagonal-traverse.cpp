class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==1){
            return matrix[0];
        }
        vector<int> ans;
        int n=matrix.size();
        int m=matrix[0].size();
        int i=0,j=0;
        while(ans.size() < n * m){
            if((i+j)%2==0){
                ans.push_back(matrix[i][j]);
                if(i==0 && j<m-1){
                    j++;
                }else if(i==0 && j==m-1){
                    i++;
                }else if(i > 0 && j == m-1){
                    i++;
                }else{
                    j++;
                    i--;
                }
            }else{
                ans.push_back(matrix[i][j]);
                if(j==0 && i==n-1){
                    j++;
                }else if(j==0 && i<n-1  ){
                    i++;
                }else if(j>0 && i==n-1){
                    j++;
                }else{
                    j--;i++;
                }
            }
        }
        return ans;
    }
};