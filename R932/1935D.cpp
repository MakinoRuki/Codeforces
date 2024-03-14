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
#define M 2005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
ll a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
      scanf("%d%d", &n, &m);
      for (int i = 1; i <= n; ++i) {
          scanf("%d", &a[i]);
      }
      ll tot = (ll)(m+1)*(ll)(m+2)/2LL;
      ll s1=0LL, s2=0LL, s3=0LL;
      ll c1=0,c0=0;
      for (int i = 1; i <= n; ++i) {
          s1 += (ll)(a[i]+2)/2LL;
          s2 += m-a[i]+1;
          if (a[i]%2) {
              c1++;
              s3 += c1;
          } else {
              c0++;
              s3 += c0;
          }
      }
      tot -= s1+s2;
      tot += s3;
      printf("%lld\n", tot);
  }
  return 0;
}
