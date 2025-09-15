
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
#define N 600005
#define M 5002
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
int b[N];
int main() {
 // freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    if (n==1) {
      printf("%lld\n", (ll)a[1]);
      continue;
    }
    ll mx1=-((1LL<<61)-1);
    ll mx2=-((1LL<<61)-1);
    ll mn1=(1LL<<61)-1;
    ll mn2=(1LL<<61)-1;
    ll ans=0LL;
    for (int i = 1; i <= n; ++i) {
      if (i&1) {
        ans += a[i];
        mx2 = max(mx2, i-2LL*a[i]);
        mn1 = min(mn1, 2LL*a[i]+i);
      } else {
        ans -= a[i];
        mx1 = max(mx1, 2LL*a[i]+i);
        mn2 = min(mn2, i-2LL*a[i]);
      }
    }
    ll dt2 = (n&1) ? n-1 : n-2;
    ll dt = max(dt2, max(mx1-mn1, mx2-mn2));
    if (dt >= 0) ans += dt;
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
