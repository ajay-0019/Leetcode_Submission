class Solution {
public:
    bool checkGoodInteger(int n) {
        if(n==0||n==1){
            return false;
        }
        int num=n;
        int squareSum=0;
        int digitSum=0;
        while(num>0){
            int temp=num%10;
            squareSum+=temp*temp;
            digitSum+=temp;
            num/=10;
        }
        return squareSum-digitSum>=50;
    }
};