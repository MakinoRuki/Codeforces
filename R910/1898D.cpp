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
#define N 300005
#define M 20
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N], b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    ll tot=0LL;
    vector<pair<int,int>> v;
    v.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
      tot += abs(a[i]-b[i]);
      int l = min(a[i], b[i]);
      int r = max(a[i], b[i]);
      v.push_back(make_pair(l, r));
    }
    ll ans = tot;
    sort(v.begin(), v.end());
    int mr=-1, ml=-1;
    for (int i = 0; i < v.size(); ++i) {
      if (i == 0) {
        mr = v[i].second;
      } else {
        if (mr < v[i].first) {
          ans = max(ans, tot + 2LL*(v[i].first-mr));
        }
      }
      mr = min(mr, v[i].second);
    }
    for (int i = v.size()-1; i >= 0; --i) {
      if (i == v.size()-1) {
        ml = v[i].first;
      } else {
        if (ml > v[i].second) {
          ans = max(ans, tot + 2LL*(ml - v[i].second));
        }
      }
      ml = max(ml, v[i].first);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
