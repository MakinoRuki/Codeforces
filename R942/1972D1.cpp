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
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
ll a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    ll ans=0;
    int qr = (int)sqrt(n+m);
    for (int i = 1; i <= min(qr, min(m, n)); ++i) {
      for (int j = i; j <= n; j += i) {
        if (((i+j)%(i*i))==0) {
          ans++;
        }
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
