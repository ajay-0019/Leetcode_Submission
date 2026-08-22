class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()){
            return "";
        }
        unordered_map<char,int> map;
        for(char c:t){
            map[c]++;
        }
        int start=0;
        int minlen=INT_MAX;
        int left=0;
        int count=0;
        for(int right=0;right<s.size();right++){
            if(map[s[right]]>0){
                count++;
            }
            map[s[right]]--;
            while(count==t.size()){
                if(right-left+1<minlen){
                    minlen=right-left+1;
                    start=left;
                }
                map[s[left]]++;
                if(map[s[left]]>0){
                    count--;
                }
                left++;
            }
        }
        if(minlen==INT_MAX){
            return "";
        }
        return s.substr(start,minlen);
    }
};