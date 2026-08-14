class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        unordered_map<char,int> map;
        int ans=1;
        int l=0;
        for(int i=0;i<n;i++){
            map[s[i]]++;
            while(map[s[i]]>2){
                map[s[l]]--;
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};