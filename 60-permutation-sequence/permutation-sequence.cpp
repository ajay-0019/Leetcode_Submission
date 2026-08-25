class Solution {
public:
    string getPermutation(int n, int k) {
        string str = "";
        for(int i = 1; i <= n; i++){
            str.push_back('0' + i); 
        }
        for(int i = 0; i < k - 1; i++){
            next_permutation(str.begin(), str.end());
        }
        return str;
    }
};
