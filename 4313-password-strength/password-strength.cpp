class Solution {
public:
    int passwordStrength(string password) {
        unordered_map<char,bool> mp;
        int ans=0;
        for(int i=0;i<password.size();i++){
            if(password[i]>=97 && password[i]<=122 && !mp[password[i]]){
                mp[password[i]]=true;
                ans++;
            }else if(password[i]>=65 && password[i]<=90 && !mp[password[i]]){
                mp[password[i]]=true;
                ans+=2;
            }else if(password[i]>=48 && password[i]<=57 && !mp[password[i]]){
                mp[password[i]]=true;
                ans+=3;
            }else if((password[i]==33 || password[i]==64 || password[i]==35 || password[i]==36) && !mp[password[i]]){
                mp[password[i]]=true;
                ans+=5;
            }
        }
        return ans;
    }
};