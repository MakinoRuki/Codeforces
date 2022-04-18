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
#define N 500005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m;
int t;
int p[N];
vector<int> edges[N];
void dfs(int u, int p, vector<int>& rk) {
  int cnt=0;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    cnt++;
    dfs(v, u, rk);
  }
  if (cnt > 0) {
    rk.push_back(cnt);
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
    }
    for (int i = 2; i <= n; ++i) {
      scanf("%d", &p[i]);
      edges[p[i]].push_back(i);
    }
    vector<int> rk;
    rk.clear();
    rk.push_back(1);
    dfs(1, 0, rk);
    set<pair<int,int>> ss;
    ss.clear();
    sort(rk.begin(), rk.end());
    int ans=0;
    while(!ss.empty() || !rk.empty()) {
      vector<pair<int,int>> tmp;
      tmp.clear();
      ans++;
      while(!ss.empty()) {
        auto pr = *ss.begin();
        ss.erase(pr);
        pr.first--;
        if (pr.first > 0) {
          tmp.push_back(pr);
        }
      }
      for (auto x : tmp) {
        ss.insert(x);
      }
      if (!rk.empty()) {
        rk.back()--;
        if (rk.back() > 0) {
          ss.insert(make_pair(rk.back(), rk.size()-1));
        }
        rk.pop_back();
      } else {
        if (!ss.empty()) {
          auto pr = *ss.rbegin();
          ss.erase(pr);
          pr.first--;
          if (pr.first > 0) {
            ss.insert(pr);
          }
        }
      }
    }
    printf("%d\n", ans);
    // int mx = 0;
    // for (int i = 0; i < rk.size(); ++i) {
    //   mx = max(mx, rk[i]);
    // }
    // int sz = (int)rk.size();
    // if (sz >= mx) {
    //   printf("%d\n", sz);
    // } else {
    //   set<pair<int,int>> ss;
    //   ss.clear();
    //   int ans = sz;
    //   for (int i = 0; i < sz; ++i) {
    //     int det = rk[i] - sz;
    //     if (det > 0) {
    //       ss.insert(make_pair(det, i));
    //     }
    //   }
    //   while(!ss.empty()) {
    //     auto pr = *ss.rbegin();
    //     ss.erase(pr);
    //     ans++;
    //     pr.first -= 2;
    //     if (pr.first > 0) {
    //       ss.insert(pr);
    //     }
    //   }
    //   printf("%d\n", ans);
    // }
  }
  return 0;
}
