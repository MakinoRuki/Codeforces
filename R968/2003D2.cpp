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
vector<int> edges[N];
int dp[N];
map<int,int> ids;
map<int,int> vs;
int cnt;
ll calc(int lb, int rb, ll mx) {
  if (lb <= rb) {
    if (mx < lb) return (ll)(lb+rb)*(ll)(rb-lb+1)/2LL;
    else if (mx >= lb && mx <= rb) {
      return mx * (ll)(mx-lb+1) + (ll)(mx+1+rb)*(ll)(rb-mx)/2LL;
    } else {
      return (ll)(rb-lb+1)*mx;
    }
  }
  return 0LL;
}
void build(vector<pair<int,int>>& tmp) {
  set<int> ss;
  ss.clear();
  for (auto pr : tmp) {
    ss.insert(pr.first);
    ss.insert(pr.second);
  }
  for (auto itr : ss) {
    if (ids.find(itr) == ids.end()) {
      ids[itr] = cnt;
      vs[cnt++] = itr;
    }
  }
  for (auto pr : tmp) {
    int l = pr.first;
    int r = pr.second;
    int lid = ids[l], rid=ids[r];
   // cout<<"lr="<<lid<<" "<<rid<<endl;
    edges[lid].push_back(rid);
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    ids.clear();
    vs.clear();
    cnt=0;
    vs[0]=0;
    ids[0] = cnt++;
    vector<pair<int,int>> tmp;
    tmp.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &k);
      set<int> ss;
      ss.clear();
      for (int j = 1; j <= k; ++j) {
        int x;
        scanf("%d", &x);
        ss.insert(x);
      }
      vector<int> v(ss.begin(), ss.end());
      int l, r;
      if (v[0] >= 2) {
        l = 0, r= 1;
      } else if (v[0] == 1) {
        int j;
        for (j = 1; j < v.size(); ++j) {
          if (v[j] != v[j-1]+1) break;
        }
        l = 0;
        r = v[j-1]+1;
      } else {
        int j;
        for (j = 1; j < v.size(); ++j) {
          if (v[j] != v[j-1]+1) break;
        }
        if (j >= v.size()) {
          l = v.back()+1;
          r = v.back()+2;
        } else {
          if (v[j-1]+2<v[j]) {
            l = v[j-1]+1;
            r = v[j-1]+2;
          } else {
            l = v[j-1]+1;
            j++;
            for (;j<v.size(); ++j) {
              if (v[j] != v[j-1]+1) break;
            }
            r = v[j-1]+1;
          }
        }
      }
      tmp.push_back(make_pair(l, r));
    }
    build(tmp);
    ll mx = -1;
    map<int,int> mp;
    mp.clear();
    for (int i = cnt-1; i >= 0; --i) {
      dp[i] = vs[i];
      for (int j = 0; j < edges[i].size(); ++j) {
        int x = edges[i][j];
        dp[i] = max(dp[i], dp[x]);
      }
      if (vs[i] <= m) {
        mp[vs[i]] = max(mp[vs[i]], dp[i]);
      }
      if (edges[i].size()>1) {
        mx = max(mx, (ll)dp[i]);
      }
      if (!edges[i].empty()) mx = max(mx, (ll)vs[i]);
      edges[i].clear();
     // cout<<"ii="<<i<<" "<<vs[i]<<" "<<dp[i]<<endl;
    }
   // cout<<"mx="<<mx<<endl;
    vector<pair<int,int>> vv;
    vv.clear();
    for (auto itr : mp) {
      vv.push_back(make_pair(itr.first, max(itr.first, itr.second)));
    }
    ll ans=0LL;
    for (int i = 0; i < vv.size(); ++i) {
     // cout<<"i="<<i<<" "<<vv[i].first<<" "<<vv[i].second<<endl;
      ans += max((ll)vv[i].second, mx);
      int lb=0, rb = vv[i].first-1;
      if (i > 0) lb = vv[i-1].first+1;
      ans += calc(lb, rb, mx);
    }
    if (vv.empty()) {
      ans += calc(0, m, mx);
    } else if (m > vv.back().first) {
      ans += calc(vv.back().first+1, m, mx);
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

