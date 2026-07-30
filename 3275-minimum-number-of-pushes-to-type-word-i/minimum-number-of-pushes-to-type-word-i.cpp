class Solution {
public:
    int minimumPushes(string word) {
        if(word.size()<=8){
            return word.size();
        }
        int ans = 0;
        int k = 1;
        int n = word.size();
        
        while (n>=8) {
            ans+=k*8;
            k++;
            n-=8;
        }
        ans+=k*n;
        return ans;
    }
};