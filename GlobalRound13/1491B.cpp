#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n,t;
int q;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll u, v;
    scanf("%d%lld%lld", &n, &u, &v);
    set<int> ss;
    ss.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      ss.insert(a[i]);
    }
    ll res;
    if ((int)ss.size() == 1) {
      res = min(u+v, 2*v);
    } else {
      res = min(u, v);
      for (int i = 1; i < n; ++i) {
        if (abs(a[i]-a[i+1]) > 1) {
          res = 0;
          break;
        }
      }
    }
    printf("%lld\n", res);
  }
  return 0;
}
