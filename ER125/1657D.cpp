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
#define M 202
#define N 1000005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int c;
ll cc[N];
vector<ll> ms;
ll cc2[N];
int main() {
  cin>>n>>c;
  memset(cc, 0LL, sizeof(cc));
  memset(cc2, 0LL, sizeof(cc2));
  for (int i = 1; i <= n; ++i) {
    ll c1, d1, h1;
    scanf("%lld%lld%lld", &c1, &d1, &h1);
    cc[c1] = max(cc[c1], d1 * h1);
  }
  cin>>m;
  ms.clear();
  for (int i =1; i <= m; ++i) {
    ll d2, h2;
    scanf("%lld%lld", &d2, &h2);
    ms.push_back(d2 * h2);
  }
  for (int i = 1; i <= c; ++i) {
    if (cc[i] > 0) {
      for (int j= i; j <= c; j += i) {
        cc2[j] = max(cc2[j], cc[i] * (ll)(j/i));
      }
    }
  }
  vector<pair<ll, ll>> rk;
  rk.clear();
  for (int i = 1; i <= c; ++i) {
    if (cc2[i] > 0) {
      rk.push_back(make_pair(cc2[i], i));
    }
  }
  sort(rk.begin(), rk.end());
  for (int i = rk.size()-2; i >= 0; --i) {
    rk[i].second = min(rk[i].second, rk[i+1].second);
  }
  for (int i = 0; i < ms.size(); ++i) {
    ll nd = ms[i];
    int l = 0, r = rk.size()-1;
    while(l < r) {
      int mid= (l+r)/2;
      if (rk[mid].first > nd) {
        r = mid;
      } else {
        l = mid+1;
      }
    }
    if (rk[r].first > nd) {
      printf("%lld", rk[r].second);
    } else {
      printf("%d", -1);
    }
    if (i < ms.size()-1) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
