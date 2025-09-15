
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
#define N 2000005
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
int c[N];
ll dp[N];
int mx[N];
int main() {
 // freopen("data.txt", "r", stdin);
  cin>>n>>m;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i =1 ; i <= n; ++i) {
    scanf("%d", &b[i]);
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &c[i]);
  }
  ll ans=0LL;
  set<pair<ll,int>> ss;
  ss.clear();
  for (int i = 1; i <= n; ++i) {
    ss.insert(make_pair(a[i]-b[i], i));
  }
  map<int,int> mp;
  mp.clear();
  for (int i = 1; i <= m; ++i) {
    mp[c[i]]++;
  }
  while(!mp.empty() && !ss.empty()) {
    auto mpr = *mp.rbegin();
    auto spr = *ss.begin();
    int id=spr.second;
    if (a[id] > mpr.first) {
      ss.erase(spr);
    } else {
      mp.erase(mpr.first);
      ll x = a[id];
      ll dt = (mpr.first-x)/spr.first+1;
      ans += 2LL*dt*mpr.second;
      mp[mpr.first-dt*spr.first] += mpr.second;
    }
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
