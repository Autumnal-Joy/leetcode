#include <iostream>
#include <vector>

using namespace std;

// f ∈ [0, n], cost = dp(n, k, n)
// 第 i 层
// 没碎 f ∈ [i, n], cost = 1 + dp(n-i, k, n)
// 碎了 f ∈ [0, i-1], cost = 1 + dp(i-1, k-1, n)

//class Solution { // Time Limit Exceeded
//public:
//    int superEggDrop(int k, int n) {
//        vector<vector<int>> dp(n + 1, vector<int>(k + 1, numeric_limits<int>::max()));
//        for (int i = 0; i <= n; ++i) {
//            dp[i][1] = i;
//        }
//        for (int j = 0; j <= k; ++j) {
//            dp[0][j] = 0;
//        }
//        for (int i = 1; i <= n; ++i) {
//            for (int j = 2; j <= k; ++j) {
//                for (int f = 1; f <= i; ++f) {
//                    dp[i][j] = std::min({dp[i][j], 1 + std::max({dp[i - f][j], dp[f - 1][j - 1]})});
//                }
//            }
//        }
//        return dp[n][k];
//    }
//};


// 假设 3 个鸡蛋扔 10 次能解的楼层范围是 [0, f]
// 第 1 次扔，从 2 个鸡蛋扔 9 次能确定的最高楼层 9+8+7+...+1 层扔
// 如果没碎，第 2 次扔，从 2 个鸡蛋扔 8 次能确定的最高楼层 8+7+6+...+1 层扔
// ...

// dp[k][n] = f 表示能解 [0, f) 范围

// dp[i,0] = 1
// dp[1,j] = j+1
// dp[2,1] = dp[1,0]
// dp[2,2] = dp[1,1] + dp[1,0]
// dp[2,10] = dp[1,9] + dp[1,8] + ... + dp[1,1] + dp[1,0]
// dp[3,10] = dp[2,9] + dp[2,8] + ... + dp[2,1] + dp[2,0]

// dp[k,n] = dp[k-1,n-1] + dp[k-1,n-2] + ... + dp[k-1,0]
// dp[k,n] = dp[k,n-1] + dp[k-1,n-1]
// dp[0,0] = 1


class Solution {
public:
    int dfs(int k, int n, vector<vector<int>> &memo) {
        if (k == 1) {
            return n + 1;
        }
        if (n == 0) {
            return 1;
        }
        if (memo[k][n] == 0) {
            memo[k][n] = dfs(k - 1, n - 1, memo) + dfs(k, n - 1, memo);
        }

        return memo[k][n];
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> memo(k + 1, vector<int>(n + 1));
        int j = 1;
        while (j <= n) {
            if (dfs(k, j, memo) > n) {
                break;
            }
            ++j;
        }
        return j;
    }
};

int main() {
    auto s = Solution();
    cout << s.superEggDrop(100, 10000) << endl;
    return 0;
}
