class Solution {
public:
    string removeOuterParentheses(string str) {
        int count=0;
        string ans="";
        for(char ch:str){
            if(ch=='('){
                if(count>0){
                    ans+=ch;
                }
                count++;
            }else{
                count--;
                if(count>0){
                    ans+=ch;
                }
            }
        }
        return ans;
    }
};