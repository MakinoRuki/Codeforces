#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int main() {
    int n;
    vector<int> L;
    scanf("%d", &n);
    vector<int> s;
    s.clear();
    for (int i = 0; i < n; ++i) {
        int l;
        scanf("%d", &l);
        L.push_back(l);
        s.push_back(i);
    }
    s.push_back(n);
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i + 1] > i) ans++;
        s[i] = i - L[i];
        s[i] = min(s[i], s[i + 1]);
    }
    printf("%d\n", ans);
    return 0;
}
