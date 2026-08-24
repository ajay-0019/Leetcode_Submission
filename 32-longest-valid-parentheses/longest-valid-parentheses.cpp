class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size()==0 || s.size()==1){
            return 0;
        }
        int n=s.size();
        stack<int> nums;
        nums.push(-1);
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                nums.push(i);
            }else{
                if(nums.size() > 1) {
                    nums.pop();
                    ans = max(ans, i - nums.top());
                }
                else {
                    nums.pop();
                    nums.push(i);
        }
            }
        }
        return ans;
    }
};