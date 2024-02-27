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
#define N 500005
#define M 15
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int h[N], p[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    vector<pair<pair<int,int>,int>> v;
    v.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &h[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &p[i]);
      v.push_back(make_pair(make_pair(p[i], h[i]), i));
    }
    sort(v.begin(), v.end());
    int id=0;
    bool ok=true;
    ll cur = k;
    ll tot=0LL;
    while(id < v.size()) {
      ll i = 1;
      int p = v[id].first.first;
      if (cur < v[id].first.second) {
        ll r = (p+2LL*cur)/(2LL*p);
        ll l = 2;
        while(l < r) {
          ll x=(l+r)/2;
          if (p >= (1LL<<61)/x || x-1>=(1LL<<61)/x) {
            l = x+1;
            continue;
          }
          if (x*(x-1)>=(1LL<<61)/p || p*(x-1)>=(1LL<<61)/x) {
            l=x+1;
            continue;
          }
          if (v[id].first.second - tot - x*cur + p*x*(x-1)/2 <= 0) {
            r = x;
          } else {
            l = x+1;
          }
        }
        if (v[id].first.second - tot - r*cur + p*r*(r-1)/2 <= 0) {
          i = r;
        } else {
          r = (p+2LL*cur)/(2LL*p)+1;
          if (v[id].first.second - tot - r*cur + p*r*(r-1)/2 <= 0) {
            i=r;
          } else {
            ok=false;
            break;
          }
        }
      }
      tot += i * cur - p*i*(i-1)/2;
      cur -= (i-1)*p;
      while(id < v.size() && tot >= v[id].first.second) {
        id++;
      }
      if (id < v.size()) {
        cur -= v[id].first.first;
      }
    }
    if (ok && id >= v.size()) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}
