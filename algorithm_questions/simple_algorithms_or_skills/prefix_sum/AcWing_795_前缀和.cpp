/**
 * @file AcWing_795_前缀和.cpp
 * @brief This is a reference code of [AcWing_795_前缀和].
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
const int N = 1e5 + 5;
int a[N];
int main() {
    int n, m; std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        a[i] += a[i - 1];
    }
    while (m--) {
        int l, r; std::cin >> l >> r;
        std::cout << a[r] - a[l - 1] << std::endl;
    }
    return 0;
}