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
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll k,x,m;
    scanf("%lld%lld%lld", &k, &x, &m);
    ll sum=0;
    bool ok=true;
    for (int i = 1; i <= x; ++i) {
      ll z = sum/(k-1)+1;
      if (sum+z > m) {
        ok=false;
        break;
      }
      sum += z;
    }
    if (ok) {
      if ((m-sum)*k<=m) {
        ok=false;
      }
    }
    if (ok) puts("YES");
    else puts("NO");
  }
  return 0;
}
