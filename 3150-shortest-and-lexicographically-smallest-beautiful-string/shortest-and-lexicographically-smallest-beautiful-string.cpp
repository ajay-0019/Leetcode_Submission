class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        unordered_map<char, int> map;
        int n = s.size();
        int left = 0;
        string ans = "";
        for (int right = 0; right < n; right++) {
            map[s[right]]++;

            while (map['1'] > k) {
                map[s[left]]--;
                left++;
            }
            while (s[left] == '0'){
                map[s[left]]--;
                left++;
            }
            if (map['1'] == k) {
                string curr =s.substr(left, right - left + 1);
                if (ans ==""||curr.size()<ans.size()||(curr.size()== ans.size() &&curr< ans)) {
                    ans = curr;
                }
            }
        }
        return ans;
    }
};
