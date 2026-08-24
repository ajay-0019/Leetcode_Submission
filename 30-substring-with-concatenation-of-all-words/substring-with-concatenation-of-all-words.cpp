class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty() || s.empty()) {
            return {};
        }

        map<string, int> mp;
        int n = s.size();
        int size = words.size();
        int wordlen = words[0].size();

        if (size * wordlen > n) {
            return {};
        }
        for (int i = 0; i < size; i++) {
            mp[words[i]]++;
        }

        vector<int> nums;
        for (int offset = 0; offset < wordlen; offset++) {

            map<string, int> ans;

            auto addstring = [&](int idx) {
                string str = "";
                for (int i = idx; i < idx + wordlen; i++) {
                    str.push_back(s[i]);
                }
                ans[str]++;
            };

            auto shrink = [&](int idx) {
                string str = "";
                for (int i = idx; i < idx + wordlen; i++) {
                    str.push_back(s[i]);
                }

                ans[str]--;

                if (ans[str] == 0) {
                    ans.erase(str);
                }
            };
            for (int i = offset;
                 i < offset + size * wordlen;
                 i += wordlen) {

                addstring(i);
            }
            if (ans == mp) {
                nums.push_back(offset);
            }
            for (int i = offset + wordlen;
                 i <= n - size * wordlen;
                 i += wordlen) {
                shrink(i - wordlen);
                addstring(i + (size - 1) * wordlen);
                if (ans == mp) {
                    nums.push_back(i);
                }
            }
        }

        return nums;
    }
};