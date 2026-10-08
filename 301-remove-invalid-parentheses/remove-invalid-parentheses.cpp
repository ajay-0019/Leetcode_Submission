    class Solution {
    public:
        unordered_set<string> ans;
        void solve(string s, int idx, int balance, int l, int r){
            if(idx==s.size()){
                if(l==0 && r==0 && balance==0){
                    ans.insert(s);
                }
                return ;
            }
            char ch=s[idx];
            if(ch=='(' && l>0){
                if(idx==0 || s[idx-1]!='('){
                    string original =s;
                    s.erase(idx,1);
                    solve(s,idx,balance,l-1,r);
                    s=original;
                }
            }
            if(ch==')' && r>0){
                if(idx==0 ||s[idx-1]!=')'){
                    string original =s;
                    s.erase(idx,1);
                    solve(s,idx,balance,l,r-1);
                    s=original;
                }
            }
          if(ch=='('){
                solve(s,idx+1,balance+1,l,r);
            }else if(ch==')'){
                if(balance>0){
                    solve(s,idx+1,balance-1,l,r);
                }
            }else{
                solve(s,idx+1,balance,l,r);
            }

        }
        vector<string> removeInvalidParentheses(string s) {
            ans.clear();
            string str;
            int l=0,r=0;
            for(auto ch:s){
                if(ch=='('){
                    l++;
                }else if(ch==')'){
                    if(l>0){
                        l--;
                    }else{
                        r++;
                    }
                }
            }
            solve(s,0,0,l,r);
            return vector<string>(ans.begin(),ans.end());
        }
    };