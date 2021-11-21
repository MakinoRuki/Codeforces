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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, h;
ll k;
vector<int> edges[N];
int p[N];
int col[N];
vector<int> ids;
void dfs(int u, int p, int c) {
  if (col[u] >= 0) return;
  col[u] = c;
  for (int i = 0; i < edges[u].size(); ++i) {
    if (edges[u][i] == p) continue;
    dfs(edges[u][i], u, !c);
  }
}
void getans(vector<int> v1, vector<int> v2) {
  for (int i = 0; i < v1.size(); ++i) {
    p[v1[i]] = v2[i];
  }
}
int main() {
  // for (int n = 1; n <= 200; ++n) {
  //   map<int, vector<int>> ps;
  //    ps.clear();
  //   for (int i = 1; i <= n; ++i) {
  //     int pw=0;
  //     while((1<<pw) <= i) pw++;
  //     pw--;
  //     ps[pw].push_back(i);
  //   }
  //   vector<pair<int,int>> rk;
  //   rk.clear();
  //   for (auto itr : ps) {
  //     rk.push_back(make_pair(-(int)itr.second.size(), itr.first));
  //   }
  //   sort(rk.begin(), rk.end());
  //   cout<<n<<" "<<-rk[0].first<<endl;
  // }

  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
      col[i] = -1;
    }
    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    dfs(1, 0, 0);
    vector<int> v1;
    vector<int> v0;
    v0.clear();
    v1.clear();
    for (int i = 1; i <= n; ++i) {
    //  cout<<"ii="<<i<<" "<<col[i]<<endl;
      if (col[i] == 0) v0.push_back(i);
      else v1.push_back(i);
    }
    map<int, vector<int>> ps;
    ps.clear();
    for (int i = 1; i <= n; ++i) {
      int pw=0;
      while((1<<pw) <= i) pw++;
      pw--;
      ps[pw].push_back(i);
    }
    int m = (int)v0.size();
    vector<int> id0;
    vector<int> id1;
    id0.clear();
    id1.clear();
    for (int i = 20; i >= 0; --i) {
      if ((1<<i) <= m) {
        auto v = ps[i];
        for (int j = 0; j < v.size(); ++j) {
          id0.push_back(v[j]);
        }
        ps.erase(i);
        m -= (int)v.size();
      }
    }
    for (auto itr : ps) {
      for (int j = 0; j < itr.second.size(); ++j) {
        id1.push_back(itr.second[j]);
      }
    }
    // vector<pair<int,int>> rk;
    // rk.clear();
    // for (auto itr : ps) {
    //   rk.push_back(make_pair(-(int)itr.second.size(), itr.first));
    // }
    // sort(rk.begin(), rk.end());
    // ids.clear();
    // for (int i = 0; i < rk.size(); ++i) {
    //   auto v = ps[rk[i].second];
    //   for (int j = 0; j < v.size(); ++j) {
    //     ids.push_back(v[j]);
    //   }
    // }
    // for (auto itr : ps) {
    //   if (itr.first == rk[0].second) {
    //     for (int j = 0; j < itr.second.size(); ++j) {
    //       ids.push_back(itr.second[j]);
    //     }
    //     break;
    //   }
    // }
    // for (auto itr : ps) {
    //   if (itr.first != rk[0].second) {
    //     for (int j = 0; j < itr.second.size(); ++j) {
    //       ids.push_back(itr.second[j]);
    //     }
    //   }
    // }
    // for (int i = 0; i < id1.size(); ++i) {
    //   cout<<"i="<<i<<" "<<id1[i]<<endl;
    // }
    // for (int i = 0; i < id2.size(); ++i) {
    //   cout<<"i2="<<i<<" "<<id2[i]<<endl;
    // }
    int cur=0;
    // if (v0.size() >= v1.size()) {
    //   cout<<v0.size()<<" "<<id2.size()<<" "<<v1.size()<<" "<<id1.size()<<endl;
    //   getans(v0, id2);
    //   getans(v1, id1);
    // } else {
    //   getans(v0, id1);
    //   getans(v1, id2);
    // }
    getans(v0, id0);
    getans(v1, id1);
    for (int i = 1; i <= n; ++i) {
      printf("%d", p[i]);
      if (i < n) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
