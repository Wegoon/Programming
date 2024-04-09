/**
 * @file AcWing_4262_空调.cpp
 * @brief This is a reference code of [AcWing_4262_空调].
 * It contains a solution to this problem.
 * 
 * @author Rookie
 * @param email None
 * @date 2024-04-09
 */

/**
 * @param algorithm 差分 + 贪心
 */
#include <iostream>
using namespace std;
const int N = 1e5 + 5;
int p[N], t[N];
int main() {
    int n; std::cin >> n;
    for (int i = 1; i <= n; i++) std::cin >> p[i];
    for (int i = 1; i <= n; i++) {
        int tmp; std::cin >> tmp;
        p[i] -= tmp;
    }
    int a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
        int tmp = p[i] - p[i - 1];
        if (tmp > 0) a += tmp;
        if (tmp < 0) b -= tmp;
    }
    std::cout << max(a, b) << std::endl;
    return 0;
}