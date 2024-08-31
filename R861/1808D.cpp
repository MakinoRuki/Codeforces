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
#define N 300005
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
  cin>>n>>k;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  ll ans = 0LL;
  map<int, vector<int>> mp;
  mp.clear();
  for (int i = 1; i <= n; ++i) {
    if (i%2) mp[a[i]].push_back(i);
  }
  for (auto itr : mp) {
    auto v = itr.second;
   // cout<<"v="<<itr.first<<endl;
    for (int i = 0; i < v.size(); ++i) {
     // cout<<"id="<<v[i]<<endl;
      int lb = max(1, k/2+1-v[i]);
      int rb = min(k/2, n-k/2-v[i]);
      if (lb <= rb) {
        int ll = lower_bound(v.begin(), v.end(), v[i]+2*lb)-v.begin();
        int rr = upper_bound(v.begin(), v.end(), v[i] + 2*rb)-v.begin()-1;
        int dt = (ll <= rr ? rr-ll+1 : 0);
        ans += rb-lb+1 - dt;
      }
    }
    //cout<<"ans="<<ans<<endl;
  }
  mp.clear();
  for (int i = 1; i <= n; ++i) {
    if ((i%2)==0) mp[a[i]].push_back(i);
  }
  for (auto itr : mp) {
    auto v = itr.second;
   // cout<<"v="<<itr.first<<endl;
    for (int i = 0; i < v.size(); ++i) {
      int lb = max(1, k/2+1-v[i]);
      int rb = min(k/2, n-k/2-v[i]);
      if (lb <= rb) {
        int ll = lower_bound(v.begin(), v.end(), v[i]+2*lb)-v.begin();
        int rr = upper_bound(v.begin(), v.end(), v[i] + 2*rb)-v.begin()-1;
        int dt = (ll <= rr ? rr-ll+1 : 0);
        ans += rb-lb+1 - dt;
      }
    }
    //cout<<"ans="<<ans<<endl;
  }
  printf("%lld\n", ans);
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
 
