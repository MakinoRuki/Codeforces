
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
#define M 10002
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
int x[N];
ll y[N];
ll z[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll k;
    scanf("%d%d%lld", &n, &m, &k);
    map<int,int> mp;
    mp.clear();
    for (int i =1 ; i <= m; ++i) {
      scanf("%d", &a[i]);
      mp[a[i]]++;
    }
    ll tot=0LL;
    vector<pair<ll,int>> rk;
    rk.clear();
    ll tot2=0LL;
    for (int i = 1; i <= n; ++i) {
      scanf("%d%lld%lld", &x[i], &y[i], &z[i]);
      tot += y[i];
      rk.push_back(make_pair(z[i]-y[i], i));
      tot2 += z[i];
    }
    if (tot2 <= k) {
      printf("%d\n", n);
      continue;
    }
    sort(rk.begin(), rk.end());
    vector<pair<ll,int>> rk2;
    rk2.clear();
    int ans=0;
    for (int i = rk.size()-1; i >= 0; --i) {
      int id = rk[i].second;
      auto itr = mp.lower_bound(x[id]);
      if (itr != mp.end()) {
        itr->second--;
        ans++;
        if (itr->second==0) mp.erase(itr);
      } else {
        rk2.push_back(rk[i]);
      }
    }
    sort(rk2.begin(), rk2.end());
    for (int i = 0; i < rk2.size(); ++i) {
      if (tot + rk2[i].first<=k) {
        ans++;
        tot += rk2[i].first;
      }
    }
    printf("%d\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
