class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        int n = s.size();

        int cycle = 2 * numRows - 2;

        int fullCycles = n / cycle;
        int rem = n % cycle;

        int cols = fullCycles * (numRows - 1);

        if (rem > 0) {
            if (rem <= numRows) {
                cols += 1;
            } else {
                cols += rem - numRows + 1;
            }
        }

        vector<vector<char>> str(numRows, vector<char>(cols, '\0'));
        int k = 0;
        auto solve = [&](auto &&self, int i, int j) -> void {
            if (i <= 0 || j >= cols || k >= n) {
                return;
            }
            str[i][j] = s[k++];

            self(self, i - 1, j + 1);
        };

        for (int j = 0; j < cols && k < n; j += numRows - 1) {
            for (int i = 0; i < numRows && k < n; i++) {
                str[i][j] = s[k++];
            }
            solve(solve, numRows - 2, j + 1);
        }

        string ans;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < cols; j++) {
                if (str[i][j] != '\0') {
                    ans += str[i][j];
                }
            }
        }

        return ans;
    }
};
