## Problem 1: Multiples of 3 or 5

### Description:

<p>If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.</p>
<p>Find the sum of all the multiples of 3 or 5 below 1000.</p>

### My solution:

```cpp
#include <iostream>
using namespace std;
// 暴力解法
int violent_solution(int n, int x, int y) {
    int sum = 0;
    for (int i = 1; i <= n; i++)
        if (i % x == 0 || i % y == 0) sum += i;
    return sum;
}

// 数学解法
int sum_solve(int n) { return (1 + n) * n / 2; }
int mathematical_solution(int n, int x, int y) {
    int a = n / x, b = n / y, c = n / (x * y);
    return sum_solve(a) * x + sum_solve(b) * y - sum_solve(c) * x * y;
}
int main() {
    cout << violent_solution(1000 - 1, 3, 5) << endl;

    cout << mathematical_solution(1000 - 1, 3, 5) << endl;

    return 0;
}
```

