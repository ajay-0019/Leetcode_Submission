class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        char ch='0';
        int ans=0;
        for(int i=0;i<=4;i++){
            if(mp[ch+i]!=0 && mp[ch+9-i]!=0){
                ans+=abs(mp[ch+i]-mp[ch+9-i]);
            }else if(mp[ch+i]!=0){
                ans+=mp[ch+i];
            }else if(mp[ch+9-i]!=0){
                ans+=mp[ch+9-i];
            }
        }
        ch='a';
        for(int i=0;i<=12;i++){
            if(mp[ch+i]!=0 && mp[ch+25-i]!=0){
                ans=ans+abs(mp[ch+i]-mp[ch+25-i]);
            }else if(mp[ch+i]!=0){
                ans+=mp[ch+i];
            }else if(mp[ch+25-i]!=0){
                ans+=mp[ch+25-i];
            }
        }
        return ans;
    }
};