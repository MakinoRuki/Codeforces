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
int n, m, q, k;
int t;
int a[N];
int par[N];
vector<pair<pair<int,int>, int>> es;
int find(int u) {
  return u == par[u] ? u : par[u] = find(par[u]);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    es.clear();
    for (int i = 1; i <= n; ++i) {
      par[i] = i;
    }
    for (int i = 1; i <= m; ++i) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      es.push_back(make_pair(make_pair(u, v),w));
    }
    ll cur = 0;
    for (int i = 30; i >= 0; --i) {
      for (int j = 1; j <= n; ++j) {
        par[j] = j;
      }
      int cnt=0;
      cur *= 2;
      for (int j = 0; j < es.size(); ++j) {
        int u = es[j].first.first;
        int v = es[j].first.second;
        int w = es[j].second;
        int k;
        for (k = 30 ; k>= i; --k) {
          if (!((1<<(k-i))&cur) && ((1<<k)&w)) {
            break;
          }
        }
        if (k >= i) continue;
        int pu = find(u);
        int pv = find(v);
        if (pu != pv) {
          par[pu] = pv;
          cnt++;
        }
      }
      if (cnt < n-1) {
        cur++;
      }
     // if (i == 3) cout<<"cur="<<cur<<endl;
    }
    printf("%lld\n", cur);
  }
  return 0;
}
