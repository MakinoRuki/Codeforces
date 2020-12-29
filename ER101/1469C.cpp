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
#define M 31
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
ll k;
ll h[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &h[i]);
    }
    ll b = h[1]+1;
    ll e = h[1]+k;
    bool ok=true;
    for (int i = 2; i <= n; ++i) {
      ll b2 = max(h[i]+1, b-k+1);
      ll e2 = min(e, h[i]+k);
      if (i == n) {
        b2 = max(h[i]+1, b-k+1);
        e2 = min(e, h[i]+1);
      }
      if (b2<=e2) {
        b = b2;
        e = e2+k-1;
      } else {
        ok = false;
        break;
      }
    }
    if (b > e) {
      ok= false;
    }
    if (ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}
