class Solution {
public:
    bool isPrime(int n){
        if(n==1){
            return false;
        }
        for(int i=2;i<=n/2;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    int sumOfPrimesInRange(int n) {
        int num=n;
        int r=0;
        while(num>0){
            int temp=num%10;
            r=r*10+temp;
            num/=10;
        }
        int ans=0;
        for(int i=min(r,n);i<=max(r,n);i++){
            if(isPrime(i)){
                ans+=i;
            }
        }
        return ans;
    }
};