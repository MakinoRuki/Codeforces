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
#define N 10000002
#define M 520
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int d;
int mp[N];
int getgcd(int x, int y) {
  return y == 0 ? x : getgcd(y, x%y);
}
int main() {
  for (int i = 1; i < N; ++i) {
    mp[i] = -1;
  }
  for (int i = 2; i < N; ++i) {
    if (mp[i] < 0) {
      for (int j = 2 * i; j < N; j += i) {
        if (mp[j] < 0) mp[j] = i;
      }
    }
  }
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    int x,y;
    scanf("%d%d", &x, &y);
    if (x < y) swap(x, y);
    int g = getgcd(x, y);
    if (g > 1) {
      puts("0");
      continue;
    }
    if (x - y == 1) {
      puts("-1");
      continue;
    }
    ll ans = (1LL<<61)-1;
    int dt = x-y;
    while(dt>1) {
   //   cout<<"dt="<<dt<<endl;
      g = mp[dt];
      if (g < 0) g= dt;
      ll k2 = (y+g-1)/g;
     // ll k1 = k2 + dt/g;
     // cout<<"kk="<<k1<<" "<<k2<<endl;
      ans = min(ans, k2 * (ll)g - y);
      while((dt % g) == 0) {
        dt/=g;
      }
    }
    if (ans >= (1LL<<61)-1) puts("-1");
    else printf("%lld\n", ans);
  }
  return 0;
}
