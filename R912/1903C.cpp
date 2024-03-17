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
ll sum[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
    }
    sum[n+1]=0;
    for (int i = n; i >= 1; --i) {
      sum[i] = sum[i+1] + a[i];
    }
    ll cur=1;
    ll tot=0LL;
    for (int i = 1; i <= n; ++i) {
      if (i == 1) {
        tot += a[i]*cur;
      } else {
        if (a[i] * cur + sum[i+1] * (cur+1) > a[i] * (cur+1) + sum[i+1] * (cur+2)) {
          tot += a[i]*cur;
        } else {
          cur++;
          tot += a[i]*cur;
        }
      }
    }
    printf("%lld\n", tot);
  }
  return 0;
}
