class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        vector<pair<char,int>> vec(mp.begin(),mp.end());
        sort(vec.begin(),vec.end(),[](const auto& lhs, const auto& rhs){
            if(lhs.second!=rhs.second){
                return lhs.second>rhs.second;
            }
            return lhs.second<rhs.second;
        });
        string ans="";
        for(auto& ch:vec){
            for(int j=0;j<ch.second;j++){
                ans+=ch.first;
            }
        }
        return ans;
    }
};