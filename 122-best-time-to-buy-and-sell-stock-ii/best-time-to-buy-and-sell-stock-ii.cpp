class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int idx=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]-idx>0){
                profit+=prices[i]-idx;
            }
            idx=prices[i];
        }
        return profit;
    }
};