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
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    ll ans=0LL;
    ll pre=0LL;
    for (int i = 2; i <= n; ++i) {
      if (a[i] >= a[i-1]) {
        ll x = a[i-1];
        int cnt=0;
        if (x > 1) {
          while(x <= a[i]) {
            x = x*x;
            cnt++;
          }
          cnt--;
        }
        pre = max(0LL, pre-cnt);
        ans += pre;
      } else {
        if (a[i] == 1) {
          ans=-1;
          break;
        }
        ll x = a[i];
        int cnt=0;
        while(x < a[i-1]) {
          x = x*x;
          cnt++;
        }
        pre += cnt;
        ans += pre;
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
