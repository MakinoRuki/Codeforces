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
#include <list>
#include <random>
#define N 500005
#define M 502
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int b[N];
int c[N];
bool vis[N];
int par[N];
bool res[N];
int cnt[N];
int find(int x) {
  return x==par[x] ? x : par[x] = find(par[x]);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    set<int> ss;
    ss.clear();
    for (int i = 1; i <= n; ++i) {
      //ss.insert(i);
      vis[i] = false;
      par[i] = i;
      res[i] = false;
      cnt[i] = 1;
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &c[i]);
      if (c[i] > 0) vis[c[i]] = true;
    }
    for (int i = 1; i <= n; ++i) {
      if (c[i] == 0) {
        int p1 = find(a[i]);
        int p2 = find(b[i]);
        if (p1 != p2) {
          bool ok = vis[p1] || vis[p2];
          par[p1] = p2;
          cnt[p2] += cnt[p1];
          vis[p2] = vis[p2] || ok;
        }
      }
    }
    ll res = 1LL;
    for (int i = 1; i <= n; ++i) {
      par[i] = find(i);
      if (par[i] == i) {
        if (!vis[i] && cnt[i] > 1) {
          res =res * 2LL % mod;
        }
      }
    }
    printf("%lld\n", res);
  }
  return 0;
}
