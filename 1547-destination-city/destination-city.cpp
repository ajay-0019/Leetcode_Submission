class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int> mp1;
        unordered_map<string,int> mp2;
        for(auto x:paths){
            mp1[x[0]]++;
            mp2[x[1]]++;
        }
        for (const auto& [key, value] : mp2){
            if(value>=1 && mp1[key]==0){
                return key;
            }
        }
        return "-1";
    }
};