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
#define M 105
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n, m, k;
int a[N];
int bit[N];
int idx[N];
int cnt;
int lowbit(int x) {
  return x&(-x);
}
void update(int id) {
  while(id <= cnt) {
    bit[id]++;
    id += lowbit(id);
  }
}
int query(int id) {
  int res=0;
  while(id) {
    res += bit[id];
    id -= lowbit(id);
  }
  return res;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<pair<int,int>> rk;
    rk.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      rk.push_back(make_pair(a[i], i));
    }
    sort(rk.begin(), rk.end());
    cnt=0;
    for (int i = 0; i < rk.size(); ++i) {
      if (i == 0 || rk[i].first != rk[i-1].first) {
        cnt++;
      }
      idx[rk[i].second] = cnt;
    }
    for (int i = 0; i <= n; ++i) {
      bit[i] = 0;
    }
    ll ans=0LL;
    for (int i = 1; i <= n; ++i) {
      int res1 = query(idx[i]-1);
      int res2 = query(cnt) - query(idx[i]);
      ans += (ll)min(res1, res2);
      update(idx[i]);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
