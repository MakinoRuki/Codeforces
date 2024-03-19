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
#define N 200005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int b[N];
int cnt[M][N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int qr = (int)sqrt(2*n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i =1; i <= n; ++i) {
      scanf("%d", &b[i]);
      if (a[i] <= qr) {
        cnt[a[i]][b[i]]++;
      }
    }
    ll ans=0LL;
    for (int i = 1; i <= qr; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (a[j] > i) {
          int bi = i*a[j]-b[j];
          if (bi >= 1 && bi <=n) ans += cnt[i][bi];
        } else if (a[j] == i) {
          int bi = i*a[j]-b[j];
          if (bi < b[j] && bi >= 1 && bi <= n) {
            ans += cnt[i][bi];
          }
        }
      }
    }
    for (int i = 1; i <= qr; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (cnt[i][j] && ((i*i)==(j+j))) {
          ll x = cnt[i][j];
          ans += x*(x-1)/2LL;
        }
      }
    }
    printf("%lld\n", ans);
    for (int i = 1; i <= n; ++i) {
      if (a[i] <= qr) {
        cnt[a[i]][b[i]]--;
      }
    }
  }
  return 0;
}
