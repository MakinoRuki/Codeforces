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
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
vector<int> edges[N];
bool vis[N];
vector<pair<int,int>>ans;
bool dfs(int pre, int cur, vector<int>& v) {
    vis[cur]=true;
    v.push_back(cur);
    for (int i = 0; i < edges[cur].size(); ++i) {
        int uu = edges[cur][i];
        if (uu == pre) continue;
        if (uu == v[0]) {
            return true;
        }
        if (!vis[uu]) {
            if (dfs(cur, uu, v)) {
                return true;
            }
        }
    }
    v.pop_back();
    vis[cur]=false;
    return false;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
      scanf("%d%d", &n, &m);
      ans.clear();
      for (int i = 1; i <= n; ++i) {
          edges[i].clear();
          vis[i]=false;
      }
      for (int i =1; i <= m; ++i) {
          int u,v;
          scanf("%d%d", &u, &v);
          edges[u].push_back(v);
          edges[v].push_back(u);
      }
      bool found=false;
      for (int i= 1; i <= n; ++i) {
          int sz=(int)edges[i].size();
          if (sz >= 4) {
              for (int j = 0; j < edges[i].size(); ++j) {
                  int u = edges[i][j];
                  vector<int> v;
                  v.clear();
                  v.push_back(i);
                  vis[i]=true;
                  if (dfs(i, u, v)) {
                      int num=0;
                      for (int j2 = 0; j2 < edges[i].size(); ++j2) {
                          if (!vis[edges[i][j2]]) {
                              num++;
                              if (num>=2) {
                                  found=true;
                                  break;
                              }
                          }
                      }
                      if (found) {
                          for (int j = 1; j < v.size(); ++j) {
                              ans.push_back(make_pair(v[j], v[j-1]));
                          }
                          ans.push_back(make_pair(v.back(), v[0]));
                          num=0;
                          for (int j2=0;j2<edges[i].size(); ++j2) {
                              if (!vis[edges[i][j2]]) {
                                  num++;
                                  ans.push_back(make_pair(i, edges[i][j2]));
                                  if (num>=2) {
                                      break;
                                  }
                              }
                          }
                          break;
                      }
                  }
                  while(!v.empty()) {
                      vis[v.back()] = false;
                      v.pop_back();
                  }
              }
          }
          if (found) break;
      }
      if (!found) {
          puts("NO");
      } else {
          puts("YES");
          printf("%d\n", (int)ans.size());
          for (int i = 0; i < ans.size(); ++i) {
              printf("%d %d\n", ans[i].first, ans[i].second);
          }
      }
  }
  return 0;
}
