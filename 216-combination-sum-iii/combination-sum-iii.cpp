class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        auto solve=[&](auto&& self, int sum,int start){
            if(sum==n && temp.size()==k){
                ans.push_back(temp);
                return;
            }
            if(sum>n){
                return;
            }
            for(int i=start;i<=9;i++){
                temp.push_back(i);
                self(self,sum+i,i+1);
                temp.pop_back();
            }
        };
        solve(solve,0,1);
        return ans;
    }
};