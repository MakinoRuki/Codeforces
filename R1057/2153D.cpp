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
#define N 300005
#define M 40
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
ll dp[N];
vector<int> v;
ll calc(int id1, int id2, int id3) {
    if (id3<0) return abs(a[id1]-a[id2]);
    ll mx=max(a[id1], max(a[id2], a[id3]));
    ll mn=min(a[id1], min(a[id2], a[id3]));
    return mx-mn;
}
ll solve(int l, int m, ll dt) {
    dp[l] = dt;
    for (int i = l+1; i <= m; ++i) {
        dp[i] = (1LL<<61)-1;
    }
    for (int i = l; i < m; ++i) {
        if (dp[i] >= (1LL<<61)-1) continue;
        if (i+2 <= m) {
            dp[i+2] = min(dp[i+2], dp[i]+calc(i+1, i+2, -1));
        }
        if (i+3 <= m) {
            dp[i+3] = min(dp[i+3], dp[i]+calc(i+1, i+2, i+3));
        }
      // if (l==3 && m==n) cout<<"i="<<i<<" "<<dp[i+2]<<" "<<dp[i+3]<<endl;
    }
    return dp[m];
}
int main() {
 // freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    a[n+1] = a[1];
    ll ans = solve(2, n-1, calc(1, 2, n));
   // cout<<"ans1="<<ans<<endl;
    ans = min(ans, solve(2, n, calc(1, 2, -1)));
//    cout<<"ans2="<<ans<<endl;
    ans = min(ans, solve(3, n, calc(1, 2, 3)));
  //  cout<<"ans3="<<ans<<endl;
    ans = min(ans, solve(3, n+1, calc(2, 3, -1)));
//    cout<<"ans4="<<ans<<endl;
    ans = min(ans, solve(4, n+1, calc(2, 3, 4)));
  //  cout<<"ans5="<<ans<<endl;
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
