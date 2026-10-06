class Solution {
public:
    int maxPower(string s) {
        int counter=1;
        int ans=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                counter++;
                ans=max(ans,counter);
            }else{
                counter=1;
            }
        }
        return ans;
    }
};