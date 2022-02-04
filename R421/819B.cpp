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
#define N 1000005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int l, r;
int t;
string s;
int p[N];
ll bit[N];
int lowbit(int x) {
  return x&(-x);
}
void update(int id, int v) {
  while(id <= n) {
    bit[id] += v;
    id += lowbit(id);
  }
}
ll query(int id) {
  ll res=0LL;
  while(id>0) {
    res+=bit[id];
    id -= lowbit(id);
  }
  return res;
}
int main() {
  cin>>n;
  ll tot = 0LL;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &p[i]);
    tot += abs(p[i]-i);
  }
  memset(bit, 0LL, sizeof(bit));
  ll ans = tot;
  int id = 0;
  for (int i = 1; i <= n; ++i) {
    if (p[i] <= i) {
      int d = n-i;
      update(1, 1);
      update(d+1, -1);
      if (d+1<n) {
        int x = -(n-p[i])+(p[i]-1);
        update(d+1, x);
        update(d+2, -x);
      }
      int d2 = p[i]-1;
      if (d+2 <= n) update(d+2, -1);
      if (d+1+d2+1 <= n) update(d+d2+2, 1);
      int d3 = i-p[i];
      if (d+d2+1+1 <=n ) update(d+d2+2, 1);
      if (d+d2+1+d3+1<=n) update(d+d2+d3+2, -1);
    } else {
      int d = p[i]-i;
      update(1, -1);
      update(d+1, 1);
      int d2 = n-p[i];
      update(d+1, 1);
      update(d+d2+1, -1);
      if (d+d2+1 < n) {
        int x = -(n-p[i]) + (p[i]-1);
        update(d+d2+1, x);
        update(d+d2+2, -x);
      }
      if (d+d2+2 <= n) update(d+d2+2, -1);
      if (d+d2+i+1 <= n) update(d+d2+i+1, 1);
    }
  }
  for (int i = 1; i < n; ++i) {
    ll det = query(i);
    tot += det;
    if (tot < ans) {
      ans = tot;
      id = i;
    }
  }
  printf("%lld %d\n", ans, id);
  return 0;
}
