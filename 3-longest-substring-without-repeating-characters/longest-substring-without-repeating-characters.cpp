class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        int ans=0;
        int left=0;
        for(int i=0;i<s.size();i++){
            map[s[i]]++;
            while(map[s[i]]>1){
                map[s[left]]--;
                left++;
            }
            ans=max(ans,i-left+1);
        }
        return ans;
    }
};