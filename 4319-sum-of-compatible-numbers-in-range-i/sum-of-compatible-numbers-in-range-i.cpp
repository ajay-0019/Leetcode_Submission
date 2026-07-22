class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int x=n-k;
        int ans=0;
        for(x=max(1,n-k);x<=n+k;x++){
            if(abs(n-x)<=k && (n&x)==0){
                ans+=abs(x);
            }
        }
        return ans;
    }
};