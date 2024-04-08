/**
 * @file AcWing_562_壁画.cpp
 * @brief This is a reference code of [AcWing_562_壁画].
 * It contains a solution to this problem.
 * 
 * @author Rookie
 * @param email None
 * @date 2024-04-08
 */

/**
 * @param algorithm 前缀和
 */
#include <iostream>
const int N = 5e6 + 5;
int main() {
    int t; std::cin >> t;
    for (int id = 1; id <= t; ++id) {
        int n; std::cin >> n;
        std::string s; std::cin >> s;
        int sum[N] = {0};
        for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + s[i] - '0';
        int num = (n + 1) / 2, ans = 0;
        for (int i = num; i <= n; i++) ans = std::max(ans, sum[i] - sum[i - num]);
        std::cout << "Case #" << id << ": " << ans << std::endl;
    }
}