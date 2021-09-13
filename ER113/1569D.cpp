#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 52
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
int x[N], y[N];
vector<pair<int,int>> ps;
ll getans(vector<int> vs) {
  int sz = (int)vs.size();
  if (sz <= 1) {
    return 0LL;
  }
  sort(vs.begin(), vs.end());
  ll res = (ll)sz*(ll)(sz-1)/2;
  int cnt=0;
  for (int i = 0; i < vs.size(); ++i) {
    if (i == 0 || vs[i] == vs[i-1]) {
      cnt++;
    } else {
      if (cnt >= 2) {
        res -= (ll)cnt*(ll)(cnt-1)/2;
      }
      cnt=1;
    }
  }
  if (cnt >= 2) {
    res -= (ll)cnt*(ll)(cnt-1)/2;
  }
  return res;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &m, &k);
    set<int> sx;
    set<int> sy;
    sx.clear();
    sy.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &x[i]);
      sx.insert(x[i]);
    }
    for (int i = 1; i <= m; ++i) {
      scanf("%d", &y[i]);
      sy.insert(y[i]);
    }
    ps.clear();
    for (int i = 1; i <= k; ++i) {
      int xx, yy;
      scanf("%d%d", &xx, &yy);
      ps.push_back(make_pair(xx,yy));
    }
    vector<pair<int,pair<int,int>>> rk;
    rk.clear();
    for (int i = 1; i <= k; ++i) {
      if (sx.find(ps[i-1].first) == sx.end()) {
        rk.push_back(make_pair(ps[i-1].first, make_pair(1, i)));
      }
    }
    for (int i = 1; i <= n; ++i) {
      rk.push_back(make_pair(x[i], make_pair(0, 0)));
    }
    sort(rk.begin(), rk.end());
    vector<int> tmp;
    tmp.clear();
    ll ans = 0LL;
    for (int i = 0; i < rk.size(); ++i) {
   //   cout<<"i="<<i<<" "<<rk[i].first<<" "<<rk[i].second.first<<" "<<rk[i].second.second<<endl;
      if (rk[i].second.first == 0) {
        if (!tmp.empty()) {
          // for (int j = 0; j < tmp.size(); ++j) {
          //   cout<<"j="<<j<<" "<<tmp[j]<<endl;
          // }
          ans += getans(tmp);
          tmp.clear();
        }
      } else {
        int id = rk[i].second.second;
        tmp.push_back(ps[id-1].second);
      }
    }
    if (!tmp.empty()) {
      ans += getans(tmp);
    }
  //  cout<<"ans="<<ans<<endl;
    rk.clear();
    for (int i = 1; i <= k; ++i) {
      if (sy.find(ps[i-1].second) == sy.end()) {
        rk.push_back(make_pair(ps[i-1].second, make_pair(1, i)));
      }
    }
  //  cout<<"rksize="<<rk.size()<<endl;
    for (int i = 1; i <= m; ++i) {
      rk.push_back(make_pair(y[i], make_pair(0, 0)));
    }
    sort(rk.begin(), rk.end());
    tmp.clear();
    for (int i = 0; i < rk.size(); ++i) {
    //  cout<<"i="<<i<<" "<<rk[i].first<<" "<<rk[i].second.first<<" "<<rk[i].second.second<<endl;
      if (rk[i].second.first == 0) {
        if (!tmp.empty()) {
          ans += getans(tmp);
          tmp.clear();
        }
      } else {
        int id = rk[i].second.second;
        tmp.push_back(ps[id-1].first);
      }
    }
    if (!tmp.empty()) {
      ans += getans(tmp);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
