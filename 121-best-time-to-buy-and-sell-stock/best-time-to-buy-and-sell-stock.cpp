class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=INT_MIN;
        int idx=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]-idx>profit){
                profit=prices[i]-idx;
            }
            idx=min(prices[i],idx);
        }
        if(profit<0){
            return 0;
        }
        return profit;
    }
};