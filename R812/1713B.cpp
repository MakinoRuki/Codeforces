#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define N 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int cnt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      cnt[i] = 0;
    }
    int mx = -1;
    for (int i = n; i >= 1; --i) {
      if (mx > a[i]) cnt[i]++;
      mx = max(mx, a[i]);
    }
    mx = -1;
    bool found=false;
    for (int i = 1; i <= n; ++i) {
      if (mx > a[i]) cnt[i]++;
      mx = max(mx, a[i]);
      if (cnt[i] >= 2) found=true;
    }
    if (!found) puts("YES");
    else puts("NO");
  }
  return 0;
}
