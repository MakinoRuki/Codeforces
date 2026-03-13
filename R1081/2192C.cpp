
#include <iostream>
#include <sstream>
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
#include <stack>
#include <bitset>
#include <chrono>
#define N 500005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 1000003;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
int p[N];
ll sum[N];
int mn[N], mx[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int h;
    scanf("%d%d%d", &n, &h, &k);
    ll tot=0LL;
    sum[0]=0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      tot += a[i];
      sum[i] = sum[i-1]+a[i];
      mn[i] = (i==1? a[i] : min(mn[i-1], a[i]));
    }
    for (int i = n; i>= 1; --i) {
      mx[i] = (i==n?a[i] : max(mx[i+1], a[i]));
    }
    ll q = h/tot;
    ll r = h%tot;
    ll ans = q * n;
    if (r) {
      ans += q*k;
    } else {
      if (q) ans += (q-1)*k;
    }
    ll r2 = r;
    int ans2 = 0;
    if (r2) {
      for (int i = 1; i <= n; ++i) {
        ans2++;
        r2 -= a[i];
        if (r2 <= 0) break;
      }
      int ll=1,rr =n;
      while(ll < rr) {
        int mid=(ll+rr)/2;
        if (sum[mid]-mn[mid]+mx[mid+1] >= r) {
          rr = mid;
        } else {
          ll = mid+1;
        }
      }
      ans = ans + min(ans2, rr);
    }
    printf("%lld\n", ans);
  }
  return 0;
}

