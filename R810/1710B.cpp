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
#define N 200005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int a[N];
ll sum[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    vector<pair<pair<int,int>,int>> rk;
    rk.clear();
    for (int i = 1; i <= n; ++i) {
      sum[i] = 0LL;
      int x, p;
      scanf("%d%d", &x, &p);
      rk.push_back(make_pair(make_pair(x, p), i));
    }
    sort(rk.begin(), rk.end());
    set<pair<ll,int>> ss;
    ss.clear();
    int sz = (int)ss.size();
    ll tot = 0LL;
    for (int i = 1; i <= n; ++i) {
      while(!ss.empty() && (*ss.begin()).first-rk[i-1].first.first <= 0) {
        tot -= (*ss.begin()).first;
        ss.erase(*ss.begin());
        sz--;
      }
      sum[i] = rk[i-1].first.second + tot - (ll)sz * (ll)rk[i-1].first.first;
     // cout<<"i="<<i<<" "<<sum[i]<<" "<<tot<<" "<<sz<<endl;
      ss.insert(make_pair(rk[i-1].first.second + rk[i-1].first.first, i));
      tot += rk[i-1].first.second + rk[i-1].first.first;
      sz++;
    }
    ss.clear();
    tot = 0LL;
    sz = 0;
    for (int i = n; i >= 1; --i) {
      while(!ss.empty() && (*ss.begin()).first+rk[i-1].first.first <= 0) {
        tot -= (*ss.begin()).first;
        ss.erase(*ss.begin());
        sz--;
      }
      sum[i] += tot + (ll)sz * (ll)rk[i-1].first.first;
      ss.insert(make_pair(rk[i-1].first.second - rk[i-1].first.first, i));
      tot += rk[i-1].first.second - rk[i-1].first.first;
      sz++;
     // cout<<"i="<<i<<" "<<sum[i]<<endl;
    }
    string ans(n, '1');
    ss.clear();
    for (int i = 1; i <= n; ++i) {
      if (sum[i] > m) {
        ll dt = sum[i] - m;
       // if (i == 2) cout<<"dt="<<dt<<" "<<(*ss.begin()).first<<endl;
        while(!ss.empty() && (*ss.begin()).first-rk[i-1].first.first < dt) {
          int id = rk[(*ss.begin()).second-1].second;
          ans[id-1] = '0';
          ss.erase(*ss.begin());
        }
      }
      ss.insert(make_pair(rk[i-1].first.second + rk[i-1].first.first, i));
    }
    ss.clear();
    for (int i = n; i >= 1; --i) {
      if (sum[i] > m) {
        ll dt = sum[i] - m;
        while(!ss.empty() && (*ss.begin()).first+rk[i-1].first.first < dt) {
          int id = rk[(*ss.begin()).second-1].second;
          ans[id-1] = '0';
          ss.erase(*ss.begin());
        }
      }
      ss.insert(make_pair(rk[i-1].first.second - rk[i-1].first.first, i));
    }
    cout<<ans<<endl;
  }
  return 0;
}
