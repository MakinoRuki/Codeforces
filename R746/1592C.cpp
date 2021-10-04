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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, k;
int d;
ll a[N], b[N];
vector<int> edges[N];
int t;
int cnt;
ll tot;
int dfs(int u, int p) {
  ll tot2=0;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v= edges[u][i];
    if (v == p) continue;
    ll res =dfs(v, u);
    if (res == tot) {
      cnt++;
    } else {
      tot2 ^= res;
    }
  }
  tot2 ^= a[u];
//  cout<<u<<" "<<tot2<<endl;
  return tot2;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    tot=0LL;
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
      tot ^= a[i];
      edges[i].clear();
    }
    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    if (tot == 0) {
      puts("YES");
    } else {
      if (k == 2) {
        puts("NO");
        continue;
      }
      cnt=0;
      ll res = dfs(1, 0);
      // if (res == tot) {
      //   cnt++;
      // }
      // if (res == tot) {
      //   if (cnt >= 1 && cnt <= k-1) {
      //     puts("YES");
      //   } else if (cnt == 0) {
      //     puts("NO");
      //   } else {
      //     int det = cnt-(k-1);
      //     if (det % 2 == 0) {
      //       puts("YES");
      //     } else {
      //       puts("NO");
      //     }
      //   }
      // } else {
      //   puts("NO");
      // }
      if ((res == tot||res==0) && cnt >= 2)  {
        puts("YES");
      } else {
        puts("NO");
      }
    }
  }
  return 0;
}
