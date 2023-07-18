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
#define N 600005
#define M 22
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int xa,ya;
    int xb,yb;
    int xc,yc;
    ll ans = 0LL;
    scanf("%d%d%d%d%d%d", &xa, &ya, &xb, &yb, &xc, &yc);
    if ((yb>=ya&&yc>=ya) || (yb<=ya&&yc<=ya)) {
      if ((xb>=xa&&xc>=xa)||(xb<=xa&&xc<=xa)) {
        ans += min(abs(yb-ya), abs(yc-ya)) + min(abs(xb-xa), abs(xc-xa));
        ans++;
      } else {
        ans += min(abs(yb-ya), abs(yc-ya));
        ans++;
      }
    } else {
      if ((xb>=xa&&xc>=xa)||(xb<=xa&&xc<=xa)) {
        ans += min(abs(xb-xa), abs(xc-xa));
        ans++;
      } else {
        ans++;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
