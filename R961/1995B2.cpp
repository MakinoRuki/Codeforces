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
int c[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll m;
    scanf("%d%lld", &n, &m);
    vector<pair<int,int>> v;
    v.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &c[i]);
      v.push_back(make_pair(a[i], c[i]));
    }
    sort(v.begin(), v.end());
    ll ans = 0LL;
    for (int i = 1; i <= n; ++i) {
      ll x = min(m/v[i-1].first, (ll)v[i-1].second);
      ans = max(ans, x*v[i-1].first);
      if (i > 1 && v[i-1].first - 1 == v[i-2].first) {
        ll y = min((m-x*v[i-1].first)/v[i-2].first, (ll)v[i-2].second);
        ans = max(ans, x*v[i-1].first + y*v[i-2].first);
      }
      if (i < n && v[i-1].first + 1 == v[i].first) {
        ll y = min((m-x*v[i-1].first)/v[i].first, (ll)v[i].second);
        ans = max(ans, x*v[i-1].first + y*v[i].first);
      }
      // 判断能不能是m，先买a再买a+1，再调整a。
      if (i < n && v[i-1].first+1 == v[i].first) {
        ll n0 = min((ll)v[i-1].second, m/v[i-1].first);
        ll n1 = min((ll)v[i].second, (m-n0*v[i-1].first)/v[i].first);
        ll r = m-n0*v[i-1].first-n1*v[i].first;
        if (r <= v[i].second-n1 && n0 >= r) {
          ans = max(ans,  m);
        } else {
          ll dt = min(n0, v[i].second-n1);
          ans = max(ans, n0*v[i-1].first+n1*v[i].first+dt);
        }
      }
    }
   // if (t == 10000 && cas==3065) cout<<m<<endl;
    printf("%lld\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
