class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> mp;
        for(int i=0;i<word.size();i++){
            mp[word[i]]++;
        }
        vector<pair<char,int>> ans(mp.begin(),mp.end());
        sort(ans.begin(), ans.end(),[](const auto &a, const auto&b){
            return a.second>b.second;
        });
        int fans=0;
        int k=1;
        for(int i=0;i<ans.size()+8;i+=8){
            for(int j=i;j<i+8 && j<ans.size();j++){
                fans=fans+ans[j].second*k;
            }
            k++;
        }
        return fans;
    }
};