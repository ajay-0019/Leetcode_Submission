class Solution {  
public:  
    double myPow(double x, int n) {  
        double ans = 1.0;  
        long long N = n;  
        bool check = false;
        if (N < 0) {  
           check = true;  
           N *= -1;  
        }
        while (N > 0) {  
            if (N % 2 == 1) {  
               ans = ans * x;  
            }  
            x = x * x;  
            N /= 2;  
        }
        if (check) {  
            return 1.0 / ans;  
        }
        return ans;  
    }  
};