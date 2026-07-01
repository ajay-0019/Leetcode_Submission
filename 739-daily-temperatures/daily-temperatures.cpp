class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> check;
        int n=temperatures.size();
        vector<int> ans(n);
        check.push(0);
        for(int i=1;i<temperatures.size();i++){
            while(!check.empty()&& temperatures[i]>temperatures[check.top()] ){
                ans[check.top()]=i-check.top();
                check.pop();
            }
            check.push(i);
        }
        ans[n-1]=0;
        return ans;
    }
};