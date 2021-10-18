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
int t, n;
vector<int> ab[N];
int cnt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      ab[i].clear();
      cnt[i] = 0;
    }
    for (int i =1 ; i <= n; ++i) {
      int a,b;
      scanf("%d%d", &a, &b);
      ab[a].push_back(b);
    }
    for (int i =1 ; i <= n; ++i) {
      for (int j = 0; j < ab[i].size(); ++j) {
        cnt[ab[i][j]]++;
      }
    }
    ll ans = 0LL;
    for (int i = 1; i <= n; ++i) {
      if (ab[i].size() > 1) {
        for (int j = 0; j < ab[i].size(); ++j) {
          cnt[ab[i][j]]--;
        }
        ll tot=0LL;
        for (int j = 0; j < ab[i].size(); ++j) {
          ans += tot + (ll)j * cnt[ab[i][j]];
          tot += cnt[ab[i][j]];
        }
        for (int j = 0; j < ab[i].size(); ++j) {
          cnt[ab[i][j]]++;
        }
      }
    }
    ll res = (ll)n*(ll)(n-1)*(ll)(n-2)/6LL;
    printf("%lld\n", res-ans);
  }
  return 0;
}
