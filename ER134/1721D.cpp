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
#define N 200005
#define M 2505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int b[N];
int a[N];
int main() {
  cin>>t;
  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
    }
    ll ans = 0LL;
    ll mk = 0LL;
    for (int i = 30; i > 0; --i) {
      map<int, int> cnt1;
      cnt1.clear();
      map<int, int> cnt2;
      cnt2.clear();
      for (int j = 1; j <= n; ++j) {
        int tmp = (a[j]>>i) & (mk >> i);
        tmp<<=1;
        if ((1<<(i-1)) & a[j]) {
          tmp++;
        }
        cnt1[tmp]++;
      }
      for (int j = 1; j <= n; ++j) {
        int tmp = (b[j]>>i) & (mk >> i);
        tmp<<=1;
        if ((1<<(i-1)) & b[j]) {
          tmp++;
        }
        cnt2[tmp]++;
      }
      bool ok = true;
      for (int j = 1; j <= n; ++j) {
        int tmp = (a[j]>>i)&(mk>>i);
        int tmp2 = tmp;
        tmp ^= (1<<(30-i))-1;
        tmp &= (mk>>i);
        tmp <<= 1;
        tmp2 <<= 1;
        if (!((1<<(i-1)) & a[j])) {
          tmp++;
        } else {
          tmp2++;
        }
        if (cnt1[tmp2] != cnt2[tmp]) {
          ok=false;
        }
      }
      for (int j = 1; j <= n; ++j) {
        int tmp = (b[j]>>i)&(mk>>i);
        int tmp2 = tmp;
        tmp ^= (1<<(30-i))-1;
        tmp &= (mk>>i);
        tmp <<= 1;
        tmp2 <<= 1;
        if (!((1<<(i-1)) & b[j])) {
          tmp++;
        } else {
          tmp2++;
        }
        if (cnt2[tmp2] != cnt1[tmp]) {
          ok=false;
        }
      }
      if (ok) {
        ans |= (1LL<<(i-1));
        mk |= (1LL<<(i-1));
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
