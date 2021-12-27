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
#define N 400005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int l, r;
int t;
ll a, b;
int par[N];
int pp[N][22];
ll sum[N];
ll ww[N];
int cnt;
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d", &n);
    
  // }
  cin>>q;
  memset(par, -1, sizeof(par));
  memset(pp, -1, sizeof(pp));
  memset(sum, 0LL, sizeof(sum));
  cnt = 1;
  ww[cnt] = 0;
  sum[cnt] = 0;
  ll ans = 0;
  while(q-->0) {
    int ty;
    scanf("%d", &ty);
    ll p, q;
    scanf("%lld%lld", &p, &q);
    ll r = p ^ ans;
    ll w = q ^ ans;
  //  cout<<"rw="<<r<<" "<<w<<endl;
    if (ty == 1) {
      par[++cnt] = r;
      ww[cnt] = w;
     // sum[cnt] = sum[par[cnt]] + w;
      if (ww[par[cnt]] >= ww[cnt]) {
        pp[cnt][0] = par[cnt];
      } else {
        int cur = par[cnt];
        for (int i = 20; i >= 0; --i) {
          if (pp[cur][i] >= 1 && ww[pp[cur][i]] < ww[cnt]) {
            cur = pp[cur][i];
          }
        }
     //   if (cnt == 3) cout<<"cur="<<cur<<" "<<pp[cur][0]<<endl;
        pp[cnt][0] = pp[cur][0];
      //  if (cnt == 3) cout<<pp[cnt][0]<<endl;
      }
      sum[cnt] = (pp[cnt][0] >= 1 ? sum[pp[cnt][0]] + w : w);
    //  if (cnt == 3) cout<<"par="<<pp[cnt][0]<<endl;
      for (int i = 1; i <= 20; ++i) {
        if (pp[cnt][i-1] >= 1 && pp[pp[cnt][i-1]][i-1] >= 1) {
          pp[cnt][i] = pp[pp[cnt][i-1]][i-1];
        }
      }
    } else {
      ll tot = ww[r];
      if (tot > w) {
        ans = 0;
      } else {
        int len = 1;
       // if (r == 7) cout<<"x="<<pp[r][1];
        for (int i = 20; i >= 0; --i) {
      //    cout<<"i="<<i<<endl;
          int p1 = pp[r][i];
        //  cout<<p1<<" "<<sum[pp[p1][0]]<<endl;
          if (p1 >= 1) {
            ll det = sum[pp[r][0]];
            if (pp[p1][0] >= 1) det -= sum[pp[p1][0]];
            if (det + tot <= w) {
              tot += det;
              len += (1<<i);
              r = p1;
            }
          }
        }
        ans = len;
      }
      printf("%lld\n", ans);
    }
  }
  return 0;
}
