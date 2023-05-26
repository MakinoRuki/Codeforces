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
#define N 200005
#define M 22
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
ll getpw(ll x, ll y) {
  ll res=1LL;
  while(y) {
    if (y&1) res=res*x%mod;
    x=x*x%mod;
    y/=2;
  }
  return res;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    map<int,int> mp;
    mp.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      mp[a[i]]++;
    }
    vector<pair<int,int>> v;
    v.clear();
    for (auto itr : mp) {
      v.push_back(make_pair(itr.first, itr.second));
    }
    ll tmp=1LL;
    ll ans = 0LL;
    int r = 0;
    // for (int i = 0; i <v.size(); ++i) {
    //   cout<<"i="<<i<<" "<<v[i].first<<" "<<v[i].second<<endl;
    // }
    for (int i = 0; i < v.size(); ++i) {

      while(r < v.size() && v[r].first - v[i].first < m) {
       // if (i == 1) cout<<"r="<<r<<" "<<v[r].first<<" "<<v[r].second<<" "<<tmp<<endl;
        tmp = tmp * ((ll)v[r].second) % mod;
       // if (i == 1) cout<<"r="<<r<<" "<<v[r].first<<" "<<v[r].second<<" "<<tmp<<endl;
        r++;
      }
      
      if (r-i == m) {
        ans = (ans + tmp) % mod;
      }
     // cout<<"i="<<i<<" "<<v[i].first<<" "<<r<<" "<<v[r].first<<" "<<tmp<<" "<<ans<<endl;
     // cout<<"i="<<" "<<r<<" "<<v[r].first<<" "<<ans<<endl;
      tmp = tmp * getpw(v[i].second, mod-2) % mod;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
