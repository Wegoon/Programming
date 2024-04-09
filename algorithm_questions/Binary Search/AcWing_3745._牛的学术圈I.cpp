/**
 * @file AcWing_3745._牛的学术圈I.cpp
 * @brief This is a reference code of [AcWing_3745._牛的学术圈I].
 * It contains a solution to this problem.
 * 
 * @author Rookie
 * @param email None
 * @date 2024-04-09
 */

/**
 * @param algorithm 二分
 */
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
int c[N];
bool check(int x, int sum) {
    for (int i = 0; i < x; i++) {
        if (c[i] == x - 1) {
            if (sum) --sum;
            else return false;
        } else if (c[i] < x) return false;
    }
    return true;
}
int main() {
    int N, L; std::cin >> N >> L;
    for (int i = 0; i < N; i++) std::cin >> c[i];
    sort(c, c + N, greater<int>());
    int l = 0, r = N;
    while (l < r) {
        int mid = l + r + 1>> 1;
        if (check(mid, L)) l = mid;
        else r = mid - 1;
    }
    std::cout << l << std::endl;
    return 0;
}

/**
 * @param algorithm 双指针
 */
#include <iostream>
#include <algorithm>
const int N = 1e5 + 5;
int c[N];
int main() {
    int n, l; std::cin >> n >> l;
    for (int i = 0; i < n; i++) std::cin >> c[i];
    std::sort(c, c + n, std::greater<int>());
    int i = 0, j = 0;
    while (l >= 0 && i < n) {
        if (c[i] >= i + 1) ++i;
        else {
            if (c[j] >= i + 1) ++j;
            else {
                if (c[j] + 1 >= i + 1 && l > 0) ++j, --l, i = std::max(i, j);
                else break;
            }
        }
    }
    std::cout << i << std::endl;
    return 0;
}