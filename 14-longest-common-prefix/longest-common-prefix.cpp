class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1){
            return strs[0];
        }
        int n=strs.size();
        string str=strs[0];
        for(int i=1;i<n;i++){
            string ans="";
            string s2=strs[i];
            for(int i=0;i<min(str.size(),s2.size());i++){
                if(str[i]==s2[i]){
                    ans.push_back(s2[i]);
                }else{
                    break;
                }
            }
            if(ans.size()==0){
                return "";
            }
            str=ans;
        }
        return str;
    }
};