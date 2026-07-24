class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i=1;i<=n;i++){
            int currpow=log2(i);
            int nobit=pow(2,currpow);
            ans.push_back(1+ans[i-nobit]);
        }
        return ans;
    }
};