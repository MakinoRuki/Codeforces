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
#define M 500005
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll hc, dc;
    ll hm, dm;
    ll k, w, a;
    scanf("%lld%lld", &hc, &dc);
    scanf("%lld%lld", &hm, &dm);
    scanf("%lld%lld%lld", &k, &w, &a);
    bool ok = false;
    for (int i = 0; i <= k; ++i) {
      ll hc2 = hc + (ll)(k-i)*a;
      ll dc2 = dc + (ll)i * w;
      ll x1 = (hc2 + dm - 1) / dm;
      ll y1 = (hm + dc2-1) / dc2;
      if (y1 <= x1) {
     //   cout<<i<<" "<<hc2<<" "<<dc2<<endl;
        ok = true;
        break;
      }
    }
    if (ok) puts("YES");
    else puts("NO");
  }
  return 0;
}
