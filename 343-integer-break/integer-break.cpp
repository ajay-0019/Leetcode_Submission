class Solution {
public:
    int integerBreak(int n) {
        if(n==2){
            return 1;
        }
        if(n==3){
            return 2;
        }
        if(n%3==0){
            return pow(3,n/3);
        }
        if(n%3==2){
            int temp=n-2;
            return pow(3,temp/3)*2;
        }
        int ans=n-1;
        return pow(3,ans/3-1)*2*2;
    }
};