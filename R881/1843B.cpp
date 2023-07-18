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
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    ll tot = 0LL;
    int cnt=0;
    bool cur = false;
    for (int i = 1; i <= n; ++i) {
      if (a[i] < 0) {
        tot -= a[i];
        if (!cur) {
          cur = true;
          cnt++;
        }
      } else {
        tot += a[i];
        if (a[i] > 0) {
          cur = false;
        }
      }
    }
    printf("%lld %d\n", tot, cnt);
  }
  return 0;
}
