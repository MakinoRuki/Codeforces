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
#define N 1000005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
vector<pair<int,int>> xy;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int a,b;
    scanf("%d%d%d%d", &n, &k, &a, &b);
    xy.clear();
    for (int i = 1; i <= n; ++i) {
      int x,y;
      scanf("%d%d", &x, &y);
      xy.push_back(make_pair(x, y));
    }
    ll da=0LL, db=0LL;
    ll ans = (ll)abs(xy[a-1].first-xy[b-1].first) + (ll)abs(xy[a-1].second-xy[b-1].second);
    if (k > 0) {
      for (int i = 1; i <= k; ++i) {
        ll d1 = (ll)abs(xy[i-1].first-xy[a-1].first)+(ll)abs(xy[i-1].second-xy[a-1].second);
        ll d2 = (ll)abs(xy[i-1].first-xy[b-1].first)+(ll)abs(xy[i-1].second-xy[b-1].second);
        if (i == 1) {
          da = d1;
          db = d2;
        } else {
          da = min(da, d1);
          db = min(db, d2);
        }
      }
      ans = min(ans, da+db);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
