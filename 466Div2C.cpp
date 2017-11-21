#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    vector<int> a;
    scanf("%d", &n);
    int d;
    int cnt1 = 0;
    int ans = 2*n;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if (i == 0) d = x;
        else d = __gcd(d, x);
        if (x == 1) cnt1++;
        a.push_back(x);
    }
    if (d > 1) {
        printf("-1\n");
    } else {
        if (cnt1) printf("%d\n", n - cnt1);
        else {
            for (int i = 0; i < n; ++i) {
                int d = a[i];
                for (int j = i + 1; j < n; ++j) {
                    d = __gcd(d, a[j]);
                    if (d == 1) {
                        ans = min(ans, j - i + n - 1);
                        break;
                    }
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
