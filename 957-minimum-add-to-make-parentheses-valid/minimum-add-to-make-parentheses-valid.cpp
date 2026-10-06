class Solution {
public:
    int minAddToMakeValid(string str) {
        int n=str.size();
        stack<char> s;
        int ans=0;
        for(int i=0;i<n;i++){
            if(str[i]==')' && s.empty()){
                ans++;
            }else if(str[i]=='('){
                s.push(str[i]);
            }else{
                s.pop();
            }
        }
        ans+=s.size();
        return ans;
    }
};