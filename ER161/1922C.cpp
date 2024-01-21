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
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
ll ls[N], lc[N];
ll rs[N], rc[N];
ll sl[N], sr[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    ls[0]=0,lc[0]=0;
    ls[1]=0,lc[1]=0;
    sl[1]=0;
    for (int i = 2; i <= n; ++i) {
      ls[i]=ls[i-1];
      lc[i]=lc[i-1];
      sl[i]=sl[i-1]+a[i]-a[i-1];
      if (i == n || a[i]-a[i-1]<a[i+1]-a[i]) {
        ls[i] += a[i]-a[i-1];
        lc[i]++;
      }
    }
    rs[n]=0,rc[n]=0;
    rs[n+1]=0,rc[n+1]=0;
    sr[n+1]=0;
    for (int i = n-1; i >= 1; --i) {
      rs[i]=rs[i+1];
      rc[i]=rc[i+1];
      sr[i]=sr[i+1]+a[i+1]-a[i];
      if (i == 1 || a[i+1]-a[i]<a[i]-a[i-1]) {
        rs[i]+= a[i+1]-a[i];
        rc[i]++;
      }
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
      int x,y;
      scanf("%d%d", &x, &y);
      ll tot=0LL;
      if (x < y) {
        tot = sr[x]-sr[y];
        tot -= rs[x]-rs[y];
        tot += rc[x]-rc[y];
      } else {
        tot = sl[x]-sl[y];
        tot -= ls[x]-ls[y];
        tot += lc[x]-lc[y];
      }
      printf("%lld\n", tot);
    }
  }
  return 0;
}
