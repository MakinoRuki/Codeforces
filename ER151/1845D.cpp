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
#define M 12
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
ll a[N];
ll sum[N];
ll mn[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    sum[0] = 0LL;
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
      sum[i] = sum[i-1] + a[i];
    }
    for (int i = n; i >= 0; --i) {
      if (i == n) mn[i] = sum[i];
      else mn[i] = min(mn[i+1], sum[i]);
    }
    ll k = sum[n];
    ll res = sum[n];
    for (int i = 0; i < n; ++i) {
      ll tmp = sum[n] + sum[i] - mn[i+1];
      if (tmp > res) {
        res=tmp;
        k = sum[i];
      }
    }
    printf("%lld\n", k);
  }
  return 0;
}
