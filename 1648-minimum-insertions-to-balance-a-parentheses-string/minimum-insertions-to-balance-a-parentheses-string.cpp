class Solution {
public:
    int minInsertions(string str) {
        int ans=0;
        int open=0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='('){
                open++;
            }else{
                 if(i+1 <str.size() && str[i+1]==')'){
                    i++;
                }else{
                    ans++;
                }
                if(open>0){
                    open--;
                }else{
                    ans++;
                }
            }
        }
        return ans+2*open;
    }
};