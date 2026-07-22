class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if(k==1){
            return r-l+1;
        }
        int ans=0;
        int i=1;
        int range=r-l;
        if(l==0){
            ans++;
        }
        while(true){
            if(pow(i,k)>r){
                break;
            }else if(pow(i,k)>=l && pow(i,k)<=r){
                ans++;
                i++;
            }else{
                i++;
            }
        }
        return ans;
    }
};