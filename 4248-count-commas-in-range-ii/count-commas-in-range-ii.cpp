class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000){
            return 0;
        }
        vector<long long> ans(6);
        ans[0] = 0;
        ans[1] = (999999 - 1000 + 1) * 1;
        ans[2] = (999999999 - 1000000 + 1) * 2 + ans[1];
        ans[3] = (999999999999 - 1000000000 + 1) * 3 + ans[2];
        ans[4] = (999999999999999 - 1000000000000 + 1) * 4 + ans[3];
        
        if(n >= 1000 && n < 1000000){
            return (n - 1000 + 1) * 1;
        } else if(n >= 1000000 && n < 1000000000){
            return (n - 1000000 + 1) * 2 + ans[1];
        } else if(n >= 1000000000 && n < 1000000000000){
            return (n - 1000000000 + 1) * 3 + ans[2];
        } else if(n >= 1000000000000 && n < 1000000000000000){
            return (n - 1000000000000 + 1) * 4 + ans[3];
        }
        
        return (n - 1000000000000000 + 1) * 5 + ans[4];
    }
};
