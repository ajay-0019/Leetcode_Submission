#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        double a = sides[0];
        double b = sides[1];
        double c = sides[2];

        if ((a + b <= c) || (a + c <= b) || (b + c <= a)) {
            return {};
        }

        const double PI = acos(-1.0);
        const double rad_to_deg = 180.0 / PI;

        double cosA = clamp((b * b + c * c - a * a) / (2.0 * b * c), -1.0, 1.0);
        double cosB = clamp((a * a + c * c - b * b) / (2.0 * a * c), -1.0, 1.0);
        double cosC = clamp((a * a + b * b - c * c) / (2.0 * a * b), -1.0, 1.0);

        double A = acos(cosA) * rad_to_deg;
        double B = acos(cosB) * rad_to_deg;
        double C = acos(cosC) * rad_to_deg;

        vector<double> ans = {A, B, C};
        sort(ans.begin(), ans.end()); // Sorts the angles in ascending order
        
        return ans;
    }
};
