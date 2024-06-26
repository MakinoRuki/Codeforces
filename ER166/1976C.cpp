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
#define N 500005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
int b[N];
ll pps[N];
ll pts[N];
ll tps[N];
ll tts[N];
ll ans[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n+m+1; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n+m+1; ++i) {
      scanf("%d", &b[i]);
      pps[i]=0;
      pts[i]=0;
      tps[i]=0;
      tts[i]=0;
      ans[i] = 0LL;
    }
    int pn=0,tn=0;
    for (int i = 1; i <= n+m+1; ++i) {
      if (a[i] > b[i]) {
        if (tn > m) {
          if (tn + pn <= n+m) {
            pps[i] += a[i];
            tps[i] += a[i];
          }
        } else {
          if (pn > n) {
            pts[i] += b[i];
            tts[i] += b[i];
          } else if (pn == n) {
            pps[i] += a[i];
            tts[i] += b[i];
          } else {
            pps[i] += a[i];
            tps[i] += a[i];
          }
        }
        pn++;
      } else {
        if (pn > n) {
          if (tn + pn <= n+m) {
            pts[i] += b[i];
            tts[i] += b[i];
          }
        } else {
          if (tn > m) {
            pps[i] += a[i];
            tps[i] += a[i];
          } else if (tn == m) {
            pps[i] += a[i];
            tts[i] += b[i];
          } else {
            pts[i] += b[i];
            tts[i] += b[i];
          }
        }
        tn++;
      }
    }
    ll ttss=0, tpss=0;
    ll ptss=0, ppss=0;
    tn=0, pn=0;
    ll sum=0LL;
    for (int i = 1; i <= n + m + 1; ++i) {
      ans[i] += sum;
      if (a[i] > b[i]) {
        pn++;
        if (pn <= n) {
          sum += a[i];
        } else {
          sum += b[i];
        }
      } else {
        tn++;
        if (tn <= m) {
          sum += b[i];
        } else {
          sum += a[i];
        }
      }
     // cout<<"i="<<i<<" "<<ans[i]<<endl;
    }
    for (int i = n+m+1; i >= 1; --i) {
      if (a[i] > b[i]) {
        ans[i] += ptss + ppss;
      } else {
        ans[i] += tpss + ttss;
      }
      ppss += pps[i];
      ptss += pts[i];
      tpss += tps[i];
      ttss += tts[i];
    }
    for (int i = 1; i <= n+m + 1; ++i) {
      printf("%lld ", ans[i]);
    }
    cout<<endl;
  }
  return 0;
}
