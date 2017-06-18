class Solution {
public:
#define INF 0x3f3f3f3f
    int smallestFactorization(int a) {
        if (a < 10) return a;
        
        int res[40];
        int j = 0;
        for (int i=9; i >1; --i) {
            while (a%i == 0) {
                res[j] = i;
                a /= i;
                ++j;
            }
        }
        if (a > 10) return 0;
        unsigned long long ans = 0;
        for (int i = j-1; i >= 0; --i) {
            ans = 10*ans + res[i];
            if (ans > 2000000000) return 0;
        }
        return ans;
    }
};
