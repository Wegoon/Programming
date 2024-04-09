/**
 * @file AcWing_503_借教室.cpp
 * @brief This is a reference code of [AcWing_503_借教室].
 * It contains a solution to this problem.
 * 
 * @author Rookie
 * @param email None
 * @date 2024-04-09
 */

/**
 * @param algorithm 差分 + 二分
 */
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
ll a[N], d[N], s[N], t[N];
bool check(int x, int n) {
    ll sum[N] = {0};
    for (int i = 1; i <= x; i++) {
        sum[s[i]] += d[i];
        sum[t[i] + 1] -= d[i];
    }
    for (int i = 1; i <= n; i++) {
        sum[i] += sum[i - 1];
        if (sum[i] > a[i]) return false;
    }
    return true;
}
int main() {
    int n, m; std::cin >> n >> m;
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    for (int i = 1; i <= m; i++) std::cin >> d[i] >> s[i] >> t[i];
    int l = 1, r = m + 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid, n)) l = mid + 1;
        else r = mid;
    }
    if (l <= m) std::cout << -1 << std::endl << l << std::endl;
    else std::cout << 0 << std::endl;
    return 0;
}