class Solution {
public:
    void solve(vector<string> &ans, string &str, int open, int close, int total, int n) {
        if (total==2*n) {
            ans.push_back(str);
            return;
        }

        if (open<n) {
            str.push_back('(');
            solve(ans,str,open+1,close,total+1,n);
            str.pop_back();
        }

        if (close<open) {
            str.push_back(')');
            solve(ans,str, open,close+ 1,total +1, n);
            str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string str="";
        vector<string> ans;
        solve(ans,str,0,0,0,n);
        return ans;
    }
};