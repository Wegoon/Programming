/**
 * @file AcWing_796_子矩阵的和.cpp
 * @brief This is a reference code of [AcWing_796_子矩阵的和].
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
const int N = 1e3 + 5;
int a[N][N];
int main() {
    int n, m, q; std::cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            std::cin >> a[i][j];
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    while (q--) {
        int x1, y1, x2, y2; std::cin >> x1 >> y1 >> x2 >> y2;
        std::cout << a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] + a[x1 - 1][y1 - 1] << std::endl;
    }
    return 0;
}