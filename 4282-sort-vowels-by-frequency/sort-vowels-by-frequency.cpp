class Solution {
public:
    string sortVowels(string &s) {
        unordered_map<char,int> mp;
        unordered_map<char,int> first;
        vector<int> idx;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='o'||s[i]=='i'||s[i]=='u'){
    mp[s[i]]++;
    if(first.find(s[i]) == first.end())
        first[s[i]] = i;
    idx.push_back(i);
}
        }
        if(ans==mp.size() ){
            return s;
        }
        if(idx.empty()) return s;
        int temp = 0;
        for(int i=0;i<5 && !mp.empty();i++){
            auto maxIt = max_element(
    mp.begin(),
    mp.end(),
    [&](const auto& p1, const auto& p2) {
        if(p1.second == p2.second)
            return first[p1.first] > first[p2.first]; // earlier occurrence first
        return p1.second < p2.second; // higher frequency first
    }
);
            int count=maxIt->second;
            char ch=maxIt->first;
            for(int j=0;j<count;j++){
                s[idx[temp++]]=ch;
            }
            mp.erase(maxIt);
        }
        return s;
    }
};