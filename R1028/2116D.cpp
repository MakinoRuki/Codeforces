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
#include <list>
#include <stack>
#include <bitset>
#include <chrono>
#define N 500005
#define M 1002
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int b[N];
int x[N], y[N], z[N];
int c[N];
bool vis[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
      c[i] = b[i];
      vis[i] = false;
    }
    for (int i = 1; i <= q; ++i) {
      scanf("%d%d%d", &x[i], &y[i], &z[i]);
    }
    for (int i = q; i >= 1; --i) {
      // if (!vis[z[i]]) {
      //   c[x[i]] = max(c[x[i]], c[z[i]]);
      //   c[y[i]] = max(c[y[i]], c[z[i]]);
      //   vis[z[i]] = true;
      // }
      int v = c[z[i]];
      c[z[i]] = 0;
      c[x[i]] = max(c[x[i]], v);
      c[y[i]] = max(c[y[i]], v);
    }
    for (int i = 1; i <= n; ++i) {
      a[i] = c[i];
    }
    for (int i = 1; i <= q; ++i) {
      c[z[i]] = min(c[x[i]], c[y[i]]);
    }
    bool ok=true;
    for (int i  = 1; i <= n; ++i) {
      if (c[i] != b[i]) {
        ok=false;
        break;
      }
    }
    if (!ok) puts("-1");
    else {
      for (int i = 1; i <= n; ++i) {
        printf("%d ", a[i]);
      }
      cout<<endl;
    }
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
