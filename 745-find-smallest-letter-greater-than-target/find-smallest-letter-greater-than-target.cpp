class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans='z'+1;
        bool temp=false;
        for(int i=0;i<letters.size();i++){
            if(target==letters[i] || target>letters[i]){
                continue;
            }
            if(letters[i]<ans){
                ans=min(ans,letters[i]);
                temp=true;
            }
        }
        if(!temp){
            ans=*min_element(letters.begin(),letters.end());
        }
        return ans;
    }
};