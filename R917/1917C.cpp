#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <ctime>
#define N 300005
#define M 2002
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[M];
int v[N];
int main() {
  cin>>t;
  int d;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &k, &d);
    int tot=0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i] == i) tot++;
    }
    for (int i = 1; i <= k; ++i) {
      scanf("%d", &v[i]);
    }
    ll ans=tot+(d-1)/2LL;
    for (int i = 1; i <= min(3*n,d-1); ++i) {
      int x = v[(i-1)%k+1];
      for (int j = 1; j <= x; ++j) {
        a[j]++;
        if (a[j] == j) tot++;
        if (a[j] == j+1) tot--;
      }
      ans=max(ans, tot+(d-i-1)/2LL);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
