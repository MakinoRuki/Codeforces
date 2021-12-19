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
#define N 400005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
ll sum[N];
int par[N];
int cnt[N];
int a[N], b[N];
ll ans[N];
int find(int x) {
  return x == par[x] ? x : par[x] = find(par[x]);
}
int main() {
  cin>>n>>m>>q;
  vector<pair<int,int>> rk;
  rk.clear();
  ll tot=0LL;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    rk.push_back(make_pair(a[i], 1));
    tot += a[i];
  }
  for (int i =1; i <= m; ++i) {
    scanf("%d", &b[i]);
    rk.push_back(make_pair(b[i], 0));
  }
  sort(rk.begin(), rk.end());
  vector<pair<int, int>> dt;
  dt.clear();
  sum[0] = 0LL;
  for (int i = 1; i <= n+m; ++i) {
    sum[i] = sum[i-1] + rk[i-1].first;
    par[i] = i;
    if (rk[i-1].second) cnt[i] = 1;
    else cnt[i] = 0;
    if (i > 1) {
      dt.push_back(make_pair(rk[i-1].first - rk[i-2].first, i));
    }
  }
  sort(dt.begin(), dt.end());
  vector<pair<int,int>> qs;
  qs.clear();
  for (int i = 1; i <= q; ++i) {
    scanf("%d", &k);
    qs.push_back(make_pair(k, i));
  }
  sort(qs.begin(), qs.end());
  int cur = 0;
  for (int i = 0; i < qs.size(); ++i) {
    while(cur < dt.size() && dt[cur].first <= qs[i].first) {
      int id = dt[cur].second;
      int p1 = find(id-1);
      int p2 = find(id);
      if (p1 != p2) {
        ll s1 = sum[p1] - sum[p1-cnt[p1]];
        ll s2 = sum[p2] - sum[p2-cnt[p2]];
        tot -= s1;
        tot -= s2;
        par[p1] = p2;
        cnt[p2] += cnt[p1];
        ll s3 = sum[p2] - sum[p2-cnt[p2]];
        tot += s3;
      }
      cur++;
    }
    ans[qs[i].second] = tot;
  }
  for (int i = 1; i <= q; ++i) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}
