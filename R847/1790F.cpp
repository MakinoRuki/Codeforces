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
#define N 200010
#define M 100
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
int c[N];
vector<int> edges[N];
ll tot;
int dis[N];
bool mk[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    tot = 0LL;
    scanf("%d%d", &n, &c[0]);
    for (int i =1; i < n; ++i) {
      scanf("%d", &c[i]);
    }
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
      dis[i] = n;
      mk[i] = false;
    }
    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    int ans = n;
    for (int i = 0; i < n; ++i) {
      ans=min(ans, dis[c[i]]);
      dis[c[i]] = 0;
      queue<int> q;
      mk[c[i]] = true;
      q.push(c[i]);
    //  cout<<"i="<<i<<" "<<c[i]<<endl;
      while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < edges[u].size(); ++i) {
          int v = edges[u][i];
          if (dis[u] + 1 < ans && dis[u] + 1 < dis[v]) {
              dis[v] = dis[u] + 1;
              if (mk[v]) ans=min(ans, dis[v]);
              q.push(v);
          }
        }
      }
      if (i > 0) printf("%d ", ans);
    }
    cout<<endl;
  }
  return 0;
}
