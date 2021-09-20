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
#define M 12
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
vector<pair<int,int>> av;
int bit[N];
int lowbit(int x) {
  return x&(-x);
}
ll query(int id) {
  ll res = 0LL;
  while(id) {
    res += bit[id];
    id -= lowbit(id);
  }
  return res;
}
void update(int id, int add) {
  while(id <= n*m) {
    bit[id] += add;
    id += lowbit(id);
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    av.clear();
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        int x;
        scanf("%d", &x);
        int id=(i-1)*m+j-1+1;
        av.push_back(make_pair(x,id));
      }
    }
    sort(av.begin(), av.end());
    ll ans = 0LL;
    for (int i = 1; i <= n*m; ++i) {
      bit[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
      vector<pair<int,int>> rk;
      rk.clear();
      for (int j = i*m; j < (i+1)*m; ++j) {
        int id = av[j].second;
        rk.push_back(make_pair(av[j].first, -id));
      }
      sort(rk.begin(), rk.end());
      for (int j = 0; j < rk.size(); ++j) {
        int id = -rk[j].second;
        ans += (ll)query(id-1);
        update(id, 1);
      }
      for (int j = 0; j < rk.size(); ++j) {
        int id = -rk[j].second;
        update(id, -1);
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
