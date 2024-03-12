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
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
      scanf("%d", &n);
      ll ans=0LL;
      for (int i = 1; i <= 2*n; ++i) {
          scanf("%d", &a[i]);
          ans += abs(a[i]);
      }
      if (n == 1) {
          ans=min(ans, (ll)abs(a[2]-a[1]));
      }
      if (n == 2) {
          ll tmp=0LL;
          for (int i = 1;  i<= 2*n; ++i) {
              tmp += abs(a[i]-2);
          }
          ans=min(ans, tmp);
      }
      if ((n % 2) == 0) {
          ll tmp=0LL;
          for (int i = 1; i <= 2*n; ++i) {
              tmp += abs(a[i] + 1);
          }
          for (int i =1; i <= 2*n; ++i) {
              ans=min(ans, tmp - abs(a[i]+1) + abs(a[i]-n));
          }
      }
      printf("%lld\n", ans);
  }
  return 0;
}
