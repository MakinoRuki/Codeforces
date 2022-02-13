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
#define M 500005
#define N 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
//int t;
string s;
vector<int> edges[N];
bool vis[N];
int main() {
  cin>>n>>m;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  vector<int> ans;
  ans.clear();
  set<int> ss;
  ss.clear();
  ss.insert(1);
  memset(vis, false, sizeof(vis));
  vis[1] = true;
  for (int i = 1; i <= n; ++i) {
    int id = *ss.begin();
    ss.erase(id);
    ans.push_back(id);
    for (int j = 0; j < edges[id].size(); ++j) {
      int u = edges[id][j];
      if (!vis[u]) {
        ss.insert(u);
        vis[u]=true;
      }
    }
  }
  for (int i = 0; i < ans.size(); ++i) {
    printf("%d", ans[i]);
    if (i < ans.size()-1) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
