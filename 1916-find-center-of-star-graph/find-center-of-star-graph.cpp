class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> mp;
        for(int i=0;i<edges.size();i++){
            for(int j=0;j<edges[i].size();j++){
                mp[edges[i][j]]++;
            }
        }
        auto maxIt = max_element(mp.begin(), mp.end(), 
    [](const auto& a, const auto& a2) { return a.second < a2.second; });
    return maxIt->first;
    }
};