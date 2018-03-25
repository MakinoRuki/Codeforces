#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 1002
#define eps 1e-7
using namespace std;
int k, q;
double pr[N];
double ans[N];
int main() {
    cin>>k>>q;
    pr[0] = 1.0;
    int cnt = 0;
    for (int d = 1; ; d++) {
        if (cnt > 1000) break;
        for (int i = k; i >= 1; --i) {
            pr[i] = (pr[i] * (double)i + pr[i - 1] * (double)(k - i + 1)) / (double)k;
        }
        for (; cnt <= 1000; cnt++) {
            if (pr[k] * 2000.0 + eps >= (double)cnt) {
                ans[cnt] = d;
            } else {
                break;
            }
        }
        pr[0] = 0.0;
    }
    for (int i = 1; i <= q; ++i) {
        int p;
        cin>>p;
        cout<<ans[p]<<endl;
    }
    return 0;
}
