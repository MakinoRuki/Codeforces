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
int ans[N];
int a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    ll r = n%m;
    ll tot=0LL;
    ll q = 0LL;
    ll cur = 1LL;
    while(r) {
      ll r2 = (r-q*m);
      ll q2 = r2*2LL/m;
      tot += r2;
      r = 2*r2;
      q = q2;
      cur++;
      if (cur > 32) {
        tot=-1;
        break;
      }
    }
    printf("%lld\n", tot);
  }
  return 0;
}
