
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
#include <stack>
#include <bitset>
#include <chrono>
#define N 500005
#define M 8002
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
ll calc(ll ls, ll rs, ll lc, ll rc, ll x, ll dt) {
  return rs-ls+(lc-rc)*x+dt;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int l, r;
    scanf("%d%d%d", &n, &l, &r);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    sort(a+1, a+n+1);
    ll ld=0LL, rd=0LL;
    for (int i = 1; i <= n; ++i) {
      if (a[i] < l) {
        ld += l-a[i];
        rd += r-a[i];
      } else if (a[i]> r) {
        ld += a[i]-l;
        rd += a[i]-r;
      }
    }
    int lb=1,rb=n;
    while(lb <= n && a[lb] < l) {
      lb++;
    }
    while(rb >= 1 && a[rb] > r) {
      rb--;
    }
    ll ls=0LL,rs=0LL;
    ll lc=0LL,rc=0LL;
    ll ans=-((1LL<<61)-1);
    if (lb <= rb) {
      for (int i = lb; i <= rb; ++i) {
        rs += a[i];
        rc++;
      }
      for (int i = lb; i <= rb; ++i) {
     //   cout<<"i="<<i<<endl;
        ll res1=calc(ls, rs, lc, rc, l, ld);
        ll res2=calc(ls, rs, lc, rc, r, rd);
        ans=max(ans, min(res1, res2));
   //     cout<<"v1="<<ls<<" "<<rs<<" "<<lc<<" "<<rc<<" "<<ans<<endl;
        rs -= a[i];
        rc--;
        ans = max(ans, min(calc(ls, rs, lc, rc, l, ld), calc(ls, rs, lc, rc, r, rd)));
    //    cout<<"v2="<<ls<<" "<<rs<<" "<<lc<<" "<<rc<<" "<<ans<<endl;
        ls += a[i];
        lc++;
    //    cout<<"v3="<<ls<<" "<<rs<<" "<<lc<<" "<<rc<<" "<<ans<<endl;
      }
      if (a[rb] < r) {
        ans = max(ans, min(calc(ls, rs, lc, rc, l, ld), calc(ls, rs, lc, rc, r, rd)));
      }
    } else {
      ans = min(ld, rd);
    }
    printf("%lld\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
