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
int pw10[M];
int main() {
  pw10[0]=1;
  for (int i = 1; i <= 7; ++i) {
    pw10[i] = pw10[i-1] * 10;
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int a,b,c;
    ll k;
    scanf("%d%d%d%lld", &a, &b, &c, &k);
    int la = pw10[a-1];
    int ra = pw10[a]-1;
    int lc = pw10[c-1];
    int rc = pw10[c]-1;
    int lb = pw10[b-1];
    int rb = pw10[b]-1;
    ll x = -1, y = -1;
    for (int i = la; i <= ra; ++i) {
      int l = lc-i;
      int r = rc-i;
      l = max(l, lb);
      r = min(r, rb);
      if (l <= r) {
        ll dt = r-l+1;
        if (dt < k) {
          k -= dt;
        } else {
          x = i;
          y = l + k-1;
          k = 0;
          break;
        }
      }
    }
    if (x < 0 || k > 0) {
      puts("-1");
    } else {
      printf("%lld + %lld = %lld\n", x, y, x+y);
    }
  }
  return 0;
}
