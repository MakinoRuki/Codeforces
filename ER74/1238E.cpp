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
#define N 2000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
ll dp[N];
int cnt[M][M];
string s;
int main() {
  cin>>n>>m;
  cin>>s;
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < n-1; ++i) {
    int x = s[i] - 'a';
    int y = s[i+1] - 'a';
    cnt[x][y]++;
    cnt[y][x]++;
  }
  for (int i = 0; i < (1<<m); ++i) {
    dp[i] = (1LL<<60)-1;
  }
  dp[0] = 0LL;
  for (int i = 0; i < (1<<m)-1; ++i) {
    ll add = 0LL;
    for (int j1 = 0; j1 < m; ++j1) {
      for (int j2 = j1 + 1; j2 < m; ++j2) {
        if (((1<<j1)&i) && !((1<<j2)&i)) {
          add += cnt[j1][j2];
        } else if (!((1<<j1)&i) && ((1<<j2)&i)) {
          add += cnt[j1][j2];
        }
      }
    }
    for (int j = 0; j < m; ++j) {
      if ((1<<j)&i) continue;
      dp[i | (1<<j)] = min(dp[i | (1<<j)], dp[i] + add);
    }
  }
  printf("%lld\n", dp[(1<<m)-1]);
  return 0;
}
