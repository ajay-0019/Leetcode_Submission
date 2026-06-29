class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0 || prices.size()==1) return 0;
        int maxi=0;
        int mini=prices[0];
        vector<int> ans;
        for(int i=1;i<prices.size();i++){
            maxi=max(maxi,prices[i]-mini);
            if(maxi>0){
                ans.push_back(maxi);
                maxi=0;
                mini=INT_MAX;
            }
            if(mini>prices[i]){
                mini=prices[i];
            }
        }
        int sum=accumulate(ans.begin(),ans.end(),0);
        return sum;
    }
};