class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<bool> num(upper + 1, false);

        for (int x:nums) {
            if (x>=lower&&x<=upper) {
                num[x]=true;
            }
        }

        vector<vector<int>> ans;
        int lowerb =-1;
        int upperb =-1;

        for (int i=lower;i<=upper;i++) {
            if (!num[i]){
                if (lowerb==-1) {
                    lowerb= i;
                }
                upperb= i;
            } 
            else {
                if (lowerb!=-1) {
                    ans.push_back({lowerb, upperb});
                    lowerb=-1;
                    upperb=-1;
                }
            }
        }
        if (lowerb!=-1) {
            ans.push_back({lowerb, upperb});
        }

        return ans;
    }
};
