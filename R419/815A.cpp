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
#define M 500005
#define N 105
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int l, r;
int t;
string s;
int g[N][N];
int main() {
  cin>>n>>m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &g[i][j]);
    }
  }
  int z = -1, ans = inf;
  for (int x = 0; x <= 500; ++x) {
    int cnt = x;
    bool ok=true;
    for (int j = 1; j <= m; ++j) {
      if (x > g[1][j]) {
        ok=false;
        break;
      }
      cnt += g[1][j] - x;
    }
  //  if (x == 2) cout<<"cnt="<<cnt<<endl;
    if (!ok) continue;
    for (int i = 2; i <= n; ++i) {
    //  if (x == 2) cout<<"i="<<i<<endl;
      if (g[i][1] < g[1][1]-x) {
        ok=false;
        break;
      }
      int r = g[i][1] - (g[1][1]-x);
      cnt += r;
      for (int j = 2; j <= m; ++j) {
        if (g[i][j] != r + g[1][j]-x) {
          ok=false;
          break;
        }
      }
      if (!ok) break;
    }
  //  if (x == 2) cout<<"cnt="<<cnt<<endl;
    if (!ok) continue;
    if (cnt < ans) {
      ans = cnt;
      z = x;
    }
  }
  if (z < 0) {
    puts("-1");
  } else {
    printf("%d\n", ans);
 //   cout<<"z="<<z<<endl;
    for (int i = 1; i <= z; ++i) {
      printf("row %d\n", 1);
    }
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= g[1][i] - z; ++j) {
        printf("col %d\n", i);
      }
    }
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j <= g[i][1] - (g[1][1]-z); ++j) {
        printf("row %d\n", i);
      }
    }
  }
  return 0;
}
