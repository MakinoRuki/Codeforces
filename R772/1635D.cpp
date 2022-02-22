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
#define M 202
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
ll a[N];
ll dp[N];
int p;
// void dfs(int cur) {
//   if (cur >= (1LL<<p)){
//     return;
//   }
//   if (cur*2+1 < (1LL<<p)) cout<<"y="<<cur*2+1<<endl;
//   if (cur * 4 < (1LL<<p)) cout<<"y="<<cur*4<<endl;
//   dfs(cur*2+1);
//   dfs(cur*4);
// }
// void dfs(ll x, set<ll>& ss) {
//   if (x >= (1LL<<p)) {
//     return;
//   }
//   // if (x*2+1 < (1LL<<p)) {
//   //   ss.insert(2*x+1);
//   // }
//   // if (4*x < (1LL<<p)) {
//   //   ss.insert(4*x);
//   // }
//   ss.insert(x);
//   dfs(2*x+1, ss);
//   dfs(4*x, ss);
// }
int main() {
  cin>>n>>p;
  set<ll> ss;
  ss.clear();
  set<ll> tmp;
  tmp.clear();
  for (int i = 1; i <=n; ++i) {
    scanf("%lld", &a[i]);
   // a[i] = rand() % 100+1;
    //cout<<a[i]<<" ";
    ss.insert(a[i]);
   // dfs(a[i], tmp);
   // cout<<"x="<<a[i]<<endl;
    //dfs(a[i]);
  }
 // cout<<endl;
  vector<ll> v;
  v.clear();
  for (int i = 1; i <=n; ++i) {
    ll x = a[i];
    bool ok = true;
    while(x) {
      if (x&1) {
        x/=2;
        if (ss.find(x) != ss.end()) {
          ok=false;
          break;
        }
      } else {
        x/=2;
        if (x && ((x%2)==0)) {
          x/=2;
          if (ss.find(x) !=ss.end()) {
            ok=false;
            break;
          }
        } else {
          break;
        }
      }
      if (!ok) break;
    }
    if (ok) v.push_back(a[i]);
  }
  memset(dp, 0, sizeof(dp));
  dp[0] = 1LL;
  for (int i= 1; i <= p+1; ++i) {
    dp[i] = dp[i-1];
    if (i-2>=0) {
      dp[i] = (dp[i] + dp[i-2]) % mod;
    }
  }
  for (int i =1; i <= p+1; ++i) {
    if (i > 1) dp[i] = (dp[i] + dp[i-1]) % mod;
  }
 // cout<<"x="<<dp[1]<<endl;
  ll ans=0LL;
  for (int i = 0; i < v.size(); ++i) {
    ll det = 0;
    ll x = v[i];
    while(x) {
      det++;
      x/=2;
    }
    det = p-det;
    if (det >= 0) ans = (ans+1) % mod;
    if (det > 0) {
     // cout<<det<<" "<<dp[det]<<endl;
      ans = (ans + dp[det]) % mod;
    }
  }
  printf("%lld\n", ans);
//  cout<<"sz="<<(int)tmp.size()<<endl;
  return 0;
}
