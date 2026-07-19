class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans =0;
        int leftgreater=0;
        int leftsmaller=0;
        int rightgreater=0;
        int rightsmaller=0;
        for(int j=1;j<rating.size()-1;j++){
            leftgreater=0;
            leftsmaller=0;
            rightgreater=0;
            rightsmaller=0;
            for(int i=0;i<j;i++){
                if(rating[i]>rating[j]){
                    leftgreater++;
                }else{
                    leftsmaller++;
                }
            }
            for(int k=j+1;k<rating.size();k++){
                if(rating[k]>rating[j]){
                    rightgreater++;
                }else{
                    rightsmaller++;
                }
            }
            ans+=leftsmaller*rightgreater;
            ans+=leftgreater*rightsmaller;
        }
        return ans;
    }
};