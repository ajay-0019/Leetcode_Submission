class Solution {
public:
    vector<int> sumZero(int n) {
        if(n==1){
            return {0};
        }
        vector<int> ans;
        if(n%2==0){
            for(int i=n;i>n/2;i--){
                if(i%2==0){
                    ans.push_back(i);
                    ans.push_back(-i);
                }else{
                    ans.push_back(-i);
                    ans.push_back(i);
                }
            }
        }else{
            for(int i=n-1;i>n/2;i--){
                if(i%2==0){
                    ans.push_back(i);
                    ans.push_back(-i);
                }else{
                    ans.push_back(-i);
                    ans.push_back(i);
                }
            }
            ans.push_back(0);
        }
        return ans;
    }
};