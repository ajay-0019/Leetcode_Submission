class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int> map1;
        map<char,int> map2;
        for(int i=0;i<s.size();i++){
            map1[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            map2[t[i]]++;
        }
        for(auto [key,value]:map2){
            if(map1.find(key)==map1.end()){
                return key;
            }else if(map1.find(key)!=map1.end() && value!=map1[key]){
                return key;
            }
        }
       return 'a'; 
    }
};