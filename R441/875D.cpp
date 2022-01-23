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
#define M 500005
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q, p;
int t;
int a[N];
int id[35];
int l[N], r[N];
bool check(int res, int x, int y) {
  for (int i = x; i <= y; ++i) {
    if (res <= a[i]) {
      return false;
    }
  }
  return true;
}
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  memset(id, -1, sizeof(id));
  for (int i = 1; i <= n; ++i) {
    l[i] = 0;
    for (int j = 0; j <= 30; ++j) {
      if ((1<<j) & a[i]) continue;
      if (id[j] >= 1) {
        l[i] = max(l[i], id[j]);
      }
    }
    l[i]++;
    for (int j = 0; j <= 30; ++j) {
      if ((1<<j) & a[i]) {
        id[j] = max(id[j], i);
      }
    }
  }
  for (int j = 0; j <= 30; ++j) {
    id[j] = n+1;
  }
  for (int i = n; i >= 1; --i) {
    r[i] = n+1;
    for (int j = 0; j <= 30; ++j) {
      if ((1<<j) & a[i]) continue;
      if (id[j] <= n) {
        r[i] = min(r[i], id[j]);
      }
    }
    r[i]--;
    for (int j = 0; j <= 30; ++j) {
      if ((1<<j) & a[i]) {
        id[j] = min(id[j], i);
      }
    }
  }
  ll ans = (ll)n*(ll)(n+1)/2;
  map<int,int> pos;
  pos.clear();
  for (int i = 1; i <= n; ++i) {
    if (pos.find(a[i]) != pos.end()) {
      int pre = pos[a[i]];
      if (l[pre] == l[i] && r[pre] == r[i]) {
        ans -= (ll)(i-pre) * (ll)(r[i] - i+1);
      } else {
        ans -= (ll)(i-l[i]+1)*(ll)(r[i]-i+1);
      }
    } else {
      ans -= (ll)(i-l[i]+1)*(ll)(r[i]-i+1);
    }
    pos[a[i]] = i;
  }
  printf("%lld\n", ans);
  return 0;
}
