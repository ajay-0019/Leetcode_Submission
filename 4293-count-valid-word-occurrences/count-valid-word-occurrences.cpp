class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s="";
        for(int i=0;i<chunks.size();i++){
            s+=chunks[i];
        }
        unordered_map<string,int> mp;
        string temp="";
        for (int i = 0; i < s.size(); i++) {
    bool isWordChar = false;

    if (s[i] >= 'a' && s[i] <= 'z') {
        isWordChar = true;
    }
    else if (s[i] == '-' &&
             i > 0 && i + 1 < s.size() &&
             s[i - 1] >= 'a' && s[i - 1] <= 'z' &&
             s[i + 1] >= 'a' && s[i + 1] <= 'z') {
        isWordChar = true;
    }

    if (isWordChar) {
        temp += s[i];
    } else {
        if (!temp.empty()) {
            mp[temp]++;
            temp.clear();
        }
    }
}

if (!temp.empty())
    mp[temp]++;
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            ans.push_back(mp[queries[i]]);
        }
        return ans;
    }
};