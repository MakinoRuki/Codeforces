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
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
int cnt[N];
int par[N];
bool vis[N];
// key 1 : 并查集。
int find(int u) {
  return u==par[u] ? u : par[u] = find(par[u]);
}
int main() {
  cin>>n>>m;
  memset(vis, false, sizeof(vis));
  memset(cnt, 0, sizeof(cnt));
  vector<pair<pair<int,int>, int>> rk;
  rk.clear();
  vector<int> ans;
  ans.clear();
  vector<int> ids;
  ids.clear();
  for (int i = 1; i <= m; ++i) {
    par[i] = i;
  }
  int id=0;
  for (int i = 1; i <= n; ++i) {
    int k;
    scanf("%d", &k);
    int x[3];
    for (int j = 1; j <= k; ++j) {
      scanf("%d", &x[j]);
    }
    if (k==2) {
      // 是按照id字典序最小而不是向量本身字典序最小。
      int pu=find(x[1]);
      int pv=find(x[2]);
      if (pu != pv) {
        par[pu] = pv;
        ans.push_back(i);
      }
    } else {
      if (id <= 0) {
        id = x[1];
        ans.push_back(i);
      } else {
        // 1个的和2个的不能分开看，要一起看。
        // 比如<1>, <3>, <1,2>, <2,3>。
        int pu = find(id);
        int pv=find(x[1]);
        if (pu != pv) {
          par[pu] = pv;
          ans.push_back(i);
        }
      }
    }
  }
  // vector<pair<pair<int,int>, int>> rk2;
  // rk2.clear();
  // for (int i = 0; i < rk.size(); ++i) {
  //   int u = rk[i].first.first;
  //   int v=rk[i].first.second;
  //   if (vis[u] && vis[v]) continue;
  //   rk2.push_back(rk[i]);
  // }
  // sort(rk.begin(), rk.end());
  // for (int i = 0; i < rk.size(); ++i) {
  //   int u = rk[i].first.first;
  //   int v = rk[i].first.second;
  //   int pu=find(u);
  //   int pv=find(v);
  //   if (pu == pv) {
  //     continue;
  //   }
  //   par[pu] = pv;
  //   cnt[u]++;
  //   cnt[v]++;
  //   ans.push_back(rk[i].second);
  // }
  ll tot=1LL;
  // key 2 : 答案直接就是2^(基向量个数)。
  for (int i = 1; i <= ans.size(); ++i) {
    tot = tot * 2LL % mod;
  }
  sort(ans.begin(), ans.end());
  printf("%lld %d\n", tot, (int)ans.size());
  for (int i = 0; i < ans.size(); ++i) {
    printf("%d", ans[i]);
    if (i < ans.size()-1) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
