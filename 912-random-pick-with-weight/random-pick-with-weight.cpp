class Solution {
private:
    vector<int> prefix;  
    mt19937 gen;
public:
    Solution(vector<int>& w) {
        prefix.resize(w.size() + 1, 0); 
        for(int i=1;i<prefix.size();i++){
            prefix[i]=prefix[i-1]+w[i-1];
        }
    }
    
    int pickIndex() {
        int n = prefix.back();
        uniform_int_distribution<int> dist(1, n);
        int num=dist(gen);
        auto it=lower_bound(prefix.begin(),prefix.end(),num);

        return distance(prefix.begin(),it)-1;
    };
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */