class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> nums;
        int n=mat.size();
        int m=mat[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for(int i=0;i<n;i++){
            int num=0;
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    num++;
                }
            }
            q.push({num,i});
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            auto num=q.top();
            ans.push_back(num.second);
            q.pop();
        }
        return ans;
    }
};