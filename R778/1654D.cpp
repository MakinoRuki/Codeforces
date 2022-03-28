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
#define M 10000002
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int b[N];
ll pw[N][21];
ll pw2[N][21];
vector<pair<int, pair<int,int>>> edges[N];
vector<pair<int,int>> fc[N];
ll ans;
ll getpw(ll x, ll y) {
  ll res = 1LL;
  while(y) {
    if (y&1) res=res*x%mod2;
    x = x*x % mod2;
    y/=2;
  }
  return res;
}
void dfs(int u, int par, ll res) {
  ans = (ans + res) % mod2;
 // cout<<"u="<<u<<" "<<ans<<endl;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i].first;
    if (v == par) continue;
    int x = edges[u][i].second.first;
    int y = edges[u][i].second.second;
    vector<int> ps;
    ps.clear();
    for (int j = 0; j < fc[x].size(); ++j) {
      int p = fc[x][j].first;
      int cnt = fc[x][j].second;
      a[p] -= cnt;
      res = (res * pw2[p][cnt]) % mod2;
     // cout<<p<<" "<<cnt<<" "<<res<<endl;
      ps.push_back(p);
    }
    for (int j = 0; j < fc[y].size(); ++j) {
      int p = fc[y][j].first;
      int cnt = fc[y][j].second;
      a[p] += cnt;
      res = (res * pw[p][cnt]) % mod2;
   //   cout<<p<<" "<<cnt<<" "<<res<<endl;
      ps.push_back(p);
    }
    for (auto p : ps) {
      b[p] = min(b[p], a[p]);
    }
    dfs(v, u, res);
    for (int j = 0; j < fc[x].size(); ++j) {
      int p = fc[x][j].first;
      int cnt = fc[x][j].second;
      a[p] += cnt;
      res = (res * pw[p][cnt]) % mod2;
     // cout<<p<<" "<<cnt<<" "<<res<<endl;
    }
    for (int j = 0; j < fc[y].size(); ++j) {
      int p = fc[y][j].first;
      int cnt = fc[y][j].second;
      a[p] -= cnt;
      res = (res * pw2[p][cnt]) % mod2;
     // cout<<p<<" "<<cnt<<" "<<res<<endl;
    }
  }
}
int main() {
  for (int i = 2; i <= 200000; ++i) {
    int x = i;
    fc[i].clear();
    for (ll j = 2; j * j <= x; ++j) {
      if (x % j == 0) {
        int cnt=0;
        while(x%j == 0) {
          cnt++;
          x/=j;
        }
        fc[i].push_back(make_pair(j, cnt));
      }
    }
    if (x > 1) {
      fc[i].push_back(make_pair(x, 1));
    }
  }
  for (int i = 1; i <= 200000; ++i) {
    pw[i][0] = 1LL;
    pw2[i][0] = 1LL;
    for (int j = 1; j <= 20; ++j) {
      pw[i][j] = getpw(i, j);
      pw2[i][j] = getpw(pw[i][j], mod2-2);
    }
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      a[i] = 0;
      b[i] = 0;
      edges[i].clear();
    }
    for (int i = 1; i < n; ++i) {
      int u, v, x, y;
      scanf("%d%d%d%d", &u, &v, &x, &y);
      edges[u].push_back(make_pair(v, make_pair(x, y)));
      edges[v].push_back(make_pair(u, make_pair(y, x)));
    }
  //  cout<<"!!!"<<getpw(2LL, mod2-1) % mod2<<" "<<getpw(2LL, mod2-2)<<endl;
    // ll x = ((2LL * getpw(2LL, mod2-2)) % mod2 + 3LL * getpw(2LL, mod2-2) % mod2) % mod2;
    // ll y = (5LL * getpw(2LL, mod2-2)) % mod2;
    //cout<<"v="<<x<<" "<<y<<endl;
  //  ll tmp=3LL * getpw(2LL, mod2-2) % mod2;
   // cout<<"tmp="<<tmp<<endl;
    ans = 0LL;
    ll cur = 1LL;
    dfs(1, 0, cur);
   // cout<<"ans??"<<ans<<" "<<(5LL*getpw(2, mod2-2)%mod2)<<endl;
    for (int i = 2; i <= n; ++i) {
      if (b[i] < 0) {
      //  cout<<i<<" "<<-b[i]<<endl;
        ans = ans * getpw(i, -b[i]) % mod2;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
