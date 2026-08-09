class Solution {
public:
const int INF=1e9;
    vector<int> shortestToChar(string s, char c) {
        vector<int> nums;
        for(int i=0;i<s.size();i++){
            if(s[i]==c){
                nums.push_back(i);
            }
        }
        vector<int> ans(s.size(),INF);
        for(int i=0;i<s.size();i++){
            for(int j=0;j<nums.size();j++){
                ans[i]=min(ans[i],abs(i-nums[j]));
            }
        }
        return ans;
    }
};