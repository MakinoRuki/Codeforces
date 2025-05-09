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
#define N 200005
#define M 1002
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
ll sum[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    int nn=0;
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &a[i]);
        if (a[i] == n) nn++;
    }
    sort(a+1, a+m+1);
    int r = m+1;
    sum[m+1] = 0LL;
    ll ans=0LL;
    for (int i = m; i >= 1; --i) {
        sum[i] = sum[i+1] + a[i];
    }
    for (int i = 1; i <= m; ++i) {
        while(r-1 >= 1 && a[r-1] + a[i] >= n) {
            r--;
        }
        int r2 = max(r, i+1);
        ll dt = m+1-r2;
        // a[i]+a[r]>=n => 可放a[i]+a[r]-n+1种。
        ans += (ll)(a[i]-n+1)*dt + sum[r2];
    }
    ans *= 2LL;
    ans -= 2LL*(ll)nn*(ll)(m-nn);
    ans -= 2LL*(ll)nn*(ll)(nn-1);
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
