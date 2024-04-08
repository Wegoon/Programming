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