/**
 * @file AcWing_1230_K倍区间.cpp
 * @brief This is a reference code of [AcWing_1230_K倍区间].
 * It contains a solution to this problem.
 * 
 * @author Rookie
 * @param email None
 * @date 2024-04-08
 */

/**
 * @param algorithm 前缀和 + 同余
 */
#include <iostream>
typedef long long ll;
const int N = 1e5 + 5;
int cnt[N];
ll a[N], ans;
int main() {
    int n, k; std::cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 0; i <= n; i++) {
        ans += cnt[a[i] % k];
        ++cnt[a[i] % k];
    }
    std::cout << ans << std::endl;
    return 0;
}