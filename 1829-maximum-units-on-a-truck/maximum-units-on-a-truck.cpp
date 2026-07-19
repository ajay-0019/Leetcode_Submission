class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const auto& a, const auto& b) {
            return a[1] > b[1];
            });
        int ans=0;
        int preans=0;
        int i=0;
        while(i < boxTypes.size()){
            if(preans+boxTypes[i][0]<=truckSize){
                ans=ans + boxTypes[i][1]*boxTypes[i][0];
                preans+=boxTypes[i][0];
            }else{
                break;
            }
            i++;
        }    
        if(i<=boxTypes.size()-1){
            int n=truckSize-preans;
            ans=ans+n*boxTypes[i][1];
        }
        return ans;
    }
};