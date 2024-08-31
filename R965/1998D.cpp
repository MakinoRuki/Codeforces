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
vector<int> edges[N];
int dis[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
      dis[i] = inf;
    }
    for (int i = 1; i <= m; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
    }
    dis[1] = 0;
    for (int i = 1; i < n; ++i) {
      dis[i+1] = min(dis[i+1], dis[i] + 1);
      for (int j = 0; j < edges[i].size(); ++j) {
        int v = edges[i][j];
        dis[v] = min(dis[v], dis[i] + 1);
      }
    }
    string ans(n-1, '0');
    ans[0] = '0';
    vector<pair<int,int>> sg;
    sg.clear();
    for (int i = 2; i < n; ++i) {
      for (int j = 0; j < edges[i-1].size(); ++j) {
        int v = edges[i-1][j];
        int tmp = dis[i-1] + 1;
        if (i <= v-tmp-1) {
          sg.push_back(make_pair(i, v-tmp-1));
        }
      }
    }
    if (sg.size() > 0) {
      sort(sg.begin(), sg.end());
      int bg = sg[0].first, ed = sg[0].second;
      for (int i = 1; i < sg.size(); ++i) {
        if (sg[i].first <= ed && sg[i].second >= bg) {
          bg = min(bg, sg[i].first);
          ed = max(ed, sg[i].second);
        } else {
          for (int j = bg; j <= ed; ++j) {
            ans[j-1] = '1';
          }
          bg = sg[i].first;
          ed = sg[i].second;
        }
      }
      for (int j = bg; j <= ed; ++j) {
        ans[j-1] = '1';
      }
    }
    for (int i = 1; i < n; ++i) {
      ans[i-1] = (ans[i-1] == '1' ? '0' : '1');
    }
    cout<<ans<<endl;
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

 
