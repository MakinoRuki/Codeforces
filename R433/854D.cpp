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
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, h;
int k;
ll dp1[N], dp2[N];
int a[N], b[N];
vector<pair<pair<int,int>,int>> fs[N];
int main() {
  cin>>n>>m>>k;
  memset(dp1, -1, sizeof(dp1));
  memset(dp2, -1, sizeof(dp2));
  memset(a, -1, sizeof(a));
  memset(b, -1, sizeof(b));
  int maxd = 0;
  for (int i = 1; i <= m; ++i) {
    int d,f,t,c;
    scanf("%d%d%d%d", &d, &f, &t, &c);
    fs[d].push_back(make_pair(make_pair(f,t), c));
    maxd = max(maxd, d);
  }
  int cnt=0;
  ll tot=0LL;
  for (int i = 1; i <= maxd; ++i) {
    if (cnt == n) {
      dp1[i] = dp1[i-1];
    }
    for (int j = 0; j < fs[i].size(); ++j) {
      int f = fs[i][j].first.first;
      int t = fs[i][j].first.second;
      int c = fs[i][j].second;
      if (f > 0 && t == 0) {
        if (a[f] < 0) {
          cnt++;
          tot += c;
          a[f] = c;
          if (cnt == n) {
            dp1[i] = tot;
          }
        } else {
          tot -= a[f];
          a[f] = min(a[f], c);
          tot += a[f];
          if (cnt == n) {
            dp1[i] = tot;
          }
        }
      }
    }
  }
  tot = 0LL;
  cnt=0;
  for (int i = maxd; i >= 1; --i) {
    if (cnt == n) {
      dp2[i] = dp2[i+1];
    }
    for (int j = 0; j < fs[i].size(); ++j) {
      int f = fs[i][j].first.first;
      int t = fs[i][j].first.second;
      int c = fs[i][j].second;
      if (f == 0 && t > 0) {
        if (b[t] < 0) {
          cnt++;
          tot += c;
          b[t] = c;
          if (cnt == n) {
            dp2[i] = tot;
          }
        } else {
          tot -= b[t];
          b[t] = min(b[t], c);
          tot += b[t];
          if (cnt == n) {
            dp2[i] = tot;
          }
        }
      }
    }
  }
//  cout<<dp1[3]<<" "<<dp2[9]<<endl;
  ll ans = -1;
  for (int i = 1; i <= maxd; ++i) {
    if (dp1[i] >= 0 && i+k+1<=maxd && dp2[i+k+1] >= 0) {
      ans = (ans < 0 ? dp1[i]+dp2[i+k+1] : min(ans, dp1[i]+dp2[i+k+1]));
    }
  }
  cout<<ans<<endl;
  return 0;
}
