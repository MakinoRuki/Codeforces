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
#define N 300005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
ll a[N];
ll b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int w,h;
    scanf("%d%d%d", &n, &w, &h);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &b[i]);
    }
    sort(a+1, a+n+1);
    sort(b+1, b+n+1);
    bool ok=true;
    ll dt=0;
    if (a[1] - w < b[1]-h) {
      ll dt0=b[1]-h-a[1]+w;
      dt += dt0;
    } else {
      ll dt0 = a[1]-w-b[1]+h;
      dt -= dt0;
    }
    ll mn = 2LL*w-2LL*h;
    for (int i =2; i <= n; ++i) {
      if (a[i]-w+dt<=b[i]-h) {
        if (dt + a[i]+w<b[i]+h) {
          ok=false;
          break;
        }
        mn = min(mn, dt+a[i]+w-b[i]-h);
      } else {
        ll dt0 = dt+a[i]-w-b[i]+h;
        if (dt0 <= mn) {
          mn -= dt0;
          mn = min(mn, 2LL*w-2LL*h);
          dt -= dt0;
        } else {
          ok=false;
          break;
        }
      }
    }
    if (ok) puts("YES");
    else puts("NO");
  }
  return 0;
}
