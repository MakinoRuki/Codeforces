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
#define M 31
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, t;
vector<int> edges[N];
ll ans[N];
int deg[N];
int w[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      deg[i] = 0;
      edges[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &w[i]);
    }
    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      deg[u]++;
      deg[v]++;
    }
    vector<pair<int,int>> rk;
    rk.clear();
    ll tot=0LL;
    for (int i = 1; i <= n; ++i) {
      tot += (ll)deg[i] * (ll)w[i];
      if (deg[i]>1) rk.push_back(make_pair(w[i], deg[i]));
    }
    sort(rk.begin(), rk.end());
    ans[n-1] = tot;
    int j = 0;
    for (int i = n-2; i >= 1; --i) {
      while(j < rk.size() && rk[j].second <= 1) {
        j++;
      }
      ans[i] = ans[i+1] - rk[j].first;
      rk[j].second--;
    }
    for (int i = 1; i < n; ++i) {
      printf("%lld", ans[i]);
      if (i < n-1) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
