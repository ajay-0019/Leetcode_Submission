class Solution {
public:
    int numTrees(int n) {
        if(n==0 || n==1){
            return 1;
        }
        int total=0;
        for(int i=1;i<=n;i++){
            total+=numTrees(n-i)*numTrees(i-1);
        }
        return total;
    }
};