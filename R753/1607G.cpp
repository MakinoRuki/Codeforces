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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, h;
int k;
int q;
int a[N], b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    ll tot = 0LL;
    for (int i = 1; i <= n; ++i) {
      scanf("%d%d", &a[i], &b[i]);
      tot += a[i]-b[i]+m;
    }
    vector<pair<int,int>> ans;
    ans.clear();
    for (int i = 1; i <= n; ++i) {
      if (m-b[i]<= 0) {
        ans.push_back(make_pair(0, m));
      } else {
        tot -= 2LL * (m-b[i]);
        ans.push_back(make_pair(m-b[i], b[i]));
      }
    }
    for (int i = 0; i < n; ++i) {
      if (tot > 0) {
        if (ans[i].first < a[i+1] && m-ans[i].first > 0) {
          ll det = min(tot/2, min((ll)m-ans[i].first, (ll)a[i+1]-ans[i].first));
          tot -= 2LL*det;
          ans[i].first += det;
          ans[i].second -= det;
        }
      }
    }
    printf("%lld\n", abs(tot));
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d %d\n", ans[i].first, ans[i].second);
    }
  }  
  return 0;
}
