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
#define N 102
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
int r[N], b[N];
int sr[N], sb[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    memset(sr, 0, sizeof(sr));
    memset(sb, 0, sizeof(sb));
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &r[i]);
      sr[i] = sr[i-1]+r[i];
    }
    cin>>m;
    for (int i = 1; i <= m; ++i) {
      scanf("%d", &b[i]);
      sb[i] = sb[i-1]+b[i];
    }
    int ans=-inf;
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= m; ++j) {
        ans=max(ans, sr[i]+sb[j]);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
