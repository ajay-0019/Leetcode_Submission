class Solution {
public:
    string removeTrailingZeros(string num) {
        string ans="";
        int i=num.size()-1;
        while(num[i]=='0'){
            i--;
        }
        while(i>=0){
            ans.push_back(num[i]);
            i--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};