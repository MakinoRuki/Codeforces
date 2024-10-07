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
#define N 500005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
int b[M][M];
int res[M][M][2];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &k, &n, &m);
    for (int i = 1; i <= k; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        scanf("%d", &b[i][j]);
        res[i][j][0] = res[i][j][1] = 0;
      }
    }
    int now = 0;
    for (int r = k; r >= 1; --r) {
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
          res[i][j][now^1] = 0;
        }
      }
      for (int i = n; i >= 1; --i) {
        for (int j = m; j >= 1; --j) {
          if (b[i][j] == a[r]) {
            int tot = 0;
            if (i+1 <= n && j + 1 <= m) tot = res[i+1][j+1][now];
            res[i][j][now^1] = !(tot > 0);
          }
        }
      }
      for (int i = n; i >= 1; --i) {
        for (int j = m; j >= 1; --j) {
          if (i+1<=n) res[i][j][now^1] += res[i+1][j][now^1];
          if (j+1<=m) res[i][j][now^1] += res[i][j+1][now^1];
          if (i+1<=n && j+1<=m) res[i][j][now^1] -= res[i+1][j+1][now^1];
        }
      }
      now ^= 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (res[i][j][now] > 0) {
          ans = 1;
        }
      }
    }
    if (ans) puts("T");
    else puts("N");
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

