class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> map;
        for(auto x:knowledge){
            map[x[0]]=x[1];
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                int idx=i+1;
                string str="";
                while(s[idx]!=')'){
                    str+=s[idx];
                    idx++;
                }
                if(map.find(str)!=map.end()){
                    ans+=map[str];
                }else{
                    ans+="?";
                }
                i=idx;
            }else{
                ans+=s[i];
            }
        }
        return ans;
    }
};