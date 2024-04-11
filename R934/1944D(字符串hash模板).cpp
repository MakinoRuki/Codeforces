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
#define N 1000005
#define M 635
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
int a[N];
int id[N][2];
ll hl[N], hr[N];
ll pw[N];
ll hashl(int l, int r) {
  if (l>r) return 0;
  return (hl[r]-(__int128)hl[l-1]*pw[r-l+1]%hmod+hmod)%hmod;
}
ll hashr(int l, int r) {
  if (l > r) return 0;
  return (hr[l]-(__int128)hr[r+1]*pw[r-l+1]%hmod+hmod)%hmod;
}
bool check(int l, int r) {
  return (hashl(l,r) != hashr(l,r));
}
int main() {
  cin>>t;
  pw[0]=1;
  for (int i = 1; i < N; ++i) {
    pw[i] = (__int128)pw[i-1]*base%hmod;
  }
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &q);
    string s;
    cin>>s;
    hl[0]=0LL;
    hr[n+1]=0LL;
    for (int i = 1; i <= n; ++i) {
      hl[i] = ((__int128)hl[i-1]*base%hmod+s[i-1]-'a')%hmod;
    }
    for (int i = n; i >= 1; --i) {
      hr[i] = ((__int128)hr[i+1]*base%hmod+s[i-1]-'a')%hmod;
    }
    for (int i = 0; i <= n; ++i) {
      id[i][0]=-1;
      id[i][1]=-1;
    }
    for (int i = 2; i <= n; ++i) {
      id[i][0] = id[i-1][0];
      id[i][1] = id[i-1][1];
      if (s[i-1] != s[i-2]) {
        id[i][0] = i;
      }
      if (i-2>=1 && s[i-1] != s[i-3]) {
        id[i][1] = i;
      }
    }
    while(q-->0) {
      int l,r;
      scanf("%d%d", &l, &r);
      if (id[r][0]<=l) {
        puts("0");
      } else {
        int len = r-l+1;
        ll up = len;
        ll ans=0LL;
        if (up%2) up--;
        if (2 <= up) {
          ans = (up/2+1)*(up/2);
          if ((len%2)==0 && len<=up) {
            ans-=len;
          }
        }
        if (id[r][1] >= l+2) {
          ans = (ll)(2+len)*(ll)(len-1)/2LL;
          ans -= len;
        }
        if (check(l, r)) {
          ans+=len;
        }
        printf("%lld\n", ans);
      }
    }
  }
  return 0;
}
