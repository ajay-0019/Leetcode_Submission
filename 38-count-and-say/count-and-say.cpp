class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        vector<string> str;
        str.push_back("1");
        str.push_back("11");
        for(int i=3;i<=n;i++){
            string s=str.back();
            string sp="";
            int num=1;
            for(int j=1;j<s.size();j++){
                if(s[j]==s[j-1]){
                    num++;
                }else{
                   string ch = to_string(num);
                    ch += s[j-1];
                    sp += ch;
                    num=1;
                }
            }
            string ch = to_string(num);
            ch += s.back();
            sp += ch;
            str.push_back(sp);
        }
        return str.back();
    }
};