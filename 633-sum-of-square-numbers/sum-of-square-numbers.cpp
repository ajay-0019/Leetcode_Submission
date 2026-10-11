class Solution {
public:
    bool judgeSquareSum(int c) {
        int left=0;
        int right=sqrt(c);
        while(right>=left){
            long long numg=1LL*left*left+right*right;
            if(numg==c){
                return true;
            }else if(numg>c){
                right--;
            }else{
                left++;
            }
        }
        return false;
    }
};