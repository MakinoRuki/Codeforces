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
#define N 200005
#define M 300005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int a[N];
ll check(vector<int>& ids) {
  ll tot=0LL;
  for (int i = 0; i < ids.size(); ++i) {
    int id = ids[i];
    ll tmp = max(a[id-1], a[id+1]);
    tot += max(0LL, tmp+1-a[id]);
  }
  return tot;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    vector<int> ids[2];
    for (int i = 2; i < n; i += 2) {
      ids[0].push_back(i);
    }
    for (int i = 3; i < n; i += 2) {
      ids[1].push_back(i);
    }
    ll ans=0LL;
    if (ids[0].size() > ids[1].size()) {
      ans = check(ids[0]);
    } else if (ids[0].size() < ids[1].size()) {
      ans =check(ids[1]);
    } else {
      ans=min(check(ids[0]), check(ids[1]));
    }
    ll res0=0, res1=0;
    if ((n % 2) == 0) {
      for (int i = 2; i < n; i += 2) {
        ll v0 = max(0LL, (ll)max(a[i-1], a[i+1])+1-a[i]);
        ll v1 = max(0LL, (ll)max(a[i], a[i+2])+1-a[i+1]);
        ll t0 = res0 + v0;
        ll t1 = min(res0, res1) + v1;
        res0 = t0;
        res1 = t1;
      }
      ans = min(ans, min(res0, res1));
    }
    printf("%lld\n", ans);
  }
  return 0;
}
