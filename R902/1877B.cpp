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
int a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    vector<pair<int,int>> v;
    v.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
      v.push_back(make_pair(b[i], a[i]));
    }
    sort(v.begin(), v.end());
    int cur=1;
    ll tot=m;
    for (int i = 1; i <= n; ++i) {
      if (i > cur) {
        tot += m;
        cur++;
      }
      if (v[i-1].first <= m) {
        int dt = min(n-cur, v[i-1].second);
        cur += dt;
        tot += (ll)dt * (ll)v[i-1].first;
      } else {
        tot += (ll)(n-cur) * (ll)m;
        break;
      }
    }
    printf("%lld\n", tot);
  }
  return 0;
}
