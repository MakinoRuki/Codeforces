#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
int a[N];
int main() {
  cin>>n;
  map<int,int> cnt;
  cnt.clear();
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
  }
  vector<pair<int,int>> rk;
  rk.clear();
  for (auto itr : cnt) {
    rk.push_back(make_pair(itr.second, itr.first));
  }
  sort(rk.begin(), rk.end());
  ll ans = rk.back().first;
  int sz=(int)rk.size();
  for (int i = 2; i <= 60; ++i) {
    if (i > rk.size()) {
      break;
    }
    ll cur = rk[sz-i].first;
    for (int j = 1; j < i; ++j) {
      cur = min(cur, (ll)rk[sz-i+j].first/(1LL<<j));
    }
    ll tot=cur;
    for (int j = 1; j < i; ++j) {
      tot += cur * (1LL<<j);
    }
    ans = max(ans, tot);
  }
  printf("%lld\n", ans);
  return 0;
}
