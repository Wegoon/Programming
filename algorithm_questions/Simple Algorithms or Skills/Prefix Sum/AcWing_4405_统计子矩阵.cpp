/**
 * @file AcWing_4405_统计子矩阵.cpp
 * @brief This is a reference code of [AcWing_4405_统计子矩阵].
 * It contains a solution to this problem.
 * 
 * @author Rookie
 * @param email None
 * @date 2024-04-08
 */

/**
 * @param algorithm 前缀和 + 双指针
 */
#include <iostream>
const int N = 5e2 + 5;
int a[N][N], sum[N];
int main () {
    int n, m, k; std::cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            std::cin >> a[i][j];
            a[i][j] += a[i - 1][j];
        }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            for (int t = 1; t <= m; ++t)
                sum[t] = sum[t - 1] + a[j][t] - a[i - 1][t];
            int l = 1, r = 1;
            while (r <= m) {
                if (sum[r] - sum[l - 1] <= k) {
                    ans += r - l + 1;
                    ++r;
                } else {
                    ++l;
                    r = std::max(l, r);
                }
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}