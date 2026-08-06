class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;i<=n+10;i++){
            int num=i;
            int sum=1;
            while(num>0){
                sum*=num%10;
                num/=10;
            }
            if(sum%t==0){
                return i;
            }
        }
        return -1;
    }
};