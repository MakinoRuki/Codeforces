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
#define N 3010
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, h;
int k;
int q;
int a[N];
int res[N][N];
int cnt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      cnt[i] = 0;
      res[i][0] = a[i];
    }
    for (int i = 1; i <= n+1000; ++i) {
      for (int j = 1; j <= n; ++j) {
        cnt[a[j]]++;
      }
      for (int j = 1; j <= n; ++j) {
        res[j][i] = cnt[a[j]];
        a[j] = res[j][i];
      }
      for (int j = 1; j <= n; ++j) {
        cnt[j] = 0;
      }
    }
    cin>>q;
    while(q-->0) {
      int x,k;
      scanf("%d%d", &x, &k);
      if (k <= n+1000) {
        printf("%d\n", res[x][k]);
      } else {
        printf("%d\n", res[x][n+1000]);
      }
    }
  }
  return 0;
}
