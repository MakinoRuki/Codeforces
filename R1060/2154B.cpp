
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
#define N 1000005
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
ll a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
    }
    ll mx=0;
    for (int i = 1; i <= n; ++i) {
      mx = max(mx, a[i]);
      if ((i%2)==0) {
        a[i] = mx;
      }
    }
    ll ans=0LL;
    for (int i = 1; i <= n; ++i) {
      if (i&1) {
        ll v = (1LL<<61)-1;
        if (i-1>=1) v=min(v, a[i-1]);
        if (i+1<=n) v=min(v, a[i+1]);
        if (a[i] > v-1) {
          ans += a[i] - (v-1);
        }
      }
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
