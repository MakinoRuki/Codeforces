#include <iostream>
#include <cstdio>
#include <stdio.h>
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
#include <cstring>
#define N 600005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q, p;
int t;
int a[N];
int sd[N];
ll fac[N];
int main() {
  cin>>k;
  memset(sd, -1, sizeof(sd));
  for (int i = 0; i < (1<<k); ++i) {
    scanf("%d", &a[i]);
    if (a[i] >= 0) {
      sd[i] = a[i]-1;
    }
  }
  fac[0] = 1LL;
  for (int i = 1; i <= (1<<k); ++i) {
    fac[i] = fac[i-1] * (ll)i % mod2;
  }
  ll ans = 1LL;
  bool ok=true;
  for (int i = k; i > 0; --i) {
    int cnt=0;
    ll pw = 1LL;
    for (int j = 0; j < (1<<i); j += 2) {
      if (sd[j] >= 0 && sd[j+1] >= 0) {
        int idx1 = min(sd[j], sd[j+1]);
        int idx2 = max(sd[j], sd[j+1]);
        if (idx1 < (1<<(i-1)) && idx2 >= (1<<(i-1))) {
          sd[j/2] = idx1;
         // cout<<"kj="<<i<<" "<<j<<" "<<idx1<<" "<<idx2<<endl;
        } else {
          ans = 0LL;
          ok=false;
          break;
        }
      } else if ((sd[j] >= 0 && sd[j+1] < 0) || (sd[j] <0 && sd[j+1] >= 0)) {
        int idx1 = min(sd[j], sd[j+1]);
        int idx2 = max(sd[j], sd[j+1]);
        if (idx2 < (1<<(i-1))) {
          cnt++;
          sd[j/2] = idx2;
        } else {
          sd[j/2] = -1;
        }
      } else {
        cnt++;
        pw = pw * 2LL % mod2;
        sd[j/2] = -1;
      }
    }
    if (!ok) break;
    ans = ans * fac[cnt] % mod2 * pw % mod2;
  }
  if (!ok) puts("0");
  else printf("%lld\n", ans);
  return 0;
}
