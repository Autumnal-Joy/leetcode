#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    long long m = 1000000007;
    vector<vector<long long>> dp;
    void stirlingNumber(int n, int k) {
        dp = vector<vector<long long>>(n + 1, vector<long long>(k + 1, 0));
        dp[0][0] = 1;
        for (long long i = 1; i <= n; ++i) {
            for (long long j = 1; j <= k; ++j) {
                // 递推公式：S(i, j) = S(i-1, j-1) + j * S(i-1, j)
                dp[i][j] = (dp[i - 1][j - 1] + (j * dp[i - 1][j]) % m) % m;
            }
        }
    }

    // i 个非空节目
    // P(x,i)*S(n,i)*y^i, i=1,..min{n,x}
    int numberOfWays(int n, int x, int y) {
        long long res = 0;
        stirlingNumber(n, x);

        long long P_x_i = 1, y_i = 1;
        for (int i = 0; i < std::min({n, x}); ++i) {
            P_x_i = (P_x_i * (x - i)) % m;
            y_i = (y_i * y) % m;
            res = (res + ((P_x_i * dp[n][i + 1] % m) * y_i) % m) % m;
        }
        return static_cast<int>(res);
    }
};
