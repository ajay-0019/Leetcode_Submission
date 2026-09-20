class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        for(int i=1;i<=s.size();i++){
            sum+=('a'-s[i-1]+26)*i;
        }
        return sum;
    }
};