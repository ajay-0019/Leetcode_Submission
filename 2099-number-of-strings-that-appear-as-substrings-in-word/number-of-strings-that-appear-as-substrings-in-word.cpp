class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        if(word.size()==0 || patterns.size()==0) return 0;
        int ans=0;
        for(string x:patterns){
            if(word.contains(x)){
                ans++;
            }
        }
        return ans;
    }
};