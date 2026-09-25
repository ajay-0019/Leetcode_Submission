class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> s;

        for (int x : nums) {
            bool destroyed = false;

            while (!s.empty() && x < 0 && s.top() > 0) {
                if (abs(s.top()) > abs(x)) {
                    destroyed = true;
                    break;
                }
                else if (abs(s.top()) == abs(x)) {
                    s.pop();
                    destroyed = true;
                    break;
                }
                else {
                    s.pop();
                }
            }

            if (!destroyed) {
                s.push(x);
            }
        }

        vector<int> ans;

        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
