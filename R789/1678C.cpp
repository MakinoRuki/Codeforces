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
#define N 5005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 2000000000;
int n, m, k, q;
int t;
int a[N];
int ls[N][N], rs[N][N];
int main() {
  cin>>t;
//  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i <= n+1; ++i) {
      for (int j = 0; j <= n; ++j) {
        ls[i][j] = 0;
        rs[i][j] = 0;
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        ls[i][j] += ls[i-1][j];
      }
      for (int j = a[i]; j <= n; ++j) {
        ls[i][j]++;
      }
    }
    for (int i = n; i >= 1; --i) {
      for (int j = 1; j <= n; ++j) {
        rs[i][j] += rs[i+1][j];
      }
      for (int j = a[i]; j <= n; ++j) {
        rs[i][j]++;
      }
    }
    ll ans=0LL;
    for (int i = 2; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
        ans += ls[i-1][a[j]-1] * rs[j+1][a[i]-1];
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
