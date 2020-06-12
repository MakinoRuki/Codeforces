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
#define N 300005
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
int p[N];
int id[N];
int cnt[N];
vector<int> edges[N];
int main() {
  cin>>n>>m;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &p[i]);
  }
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(v);
    // if (id[v] > id[u] && id[v] <= n) {
    //   cnt[id[u]]++;
    // }
  }
  int tot=0;
  set<int> pre;
  pre.clear();
  pre.insert(p[n]);
  for (int i = n-1; i >= 1; --i) {
    int cnt=0;
    int u = p[i];
    for (int j = 0; j < edges[u].size(); ++j) {
      int v = edges[u][j];
      if (pre.find(v) != pre.end()) {
        cnt++;
      }
    }
    if (cnt == pre.size()) {
      tot++;
    } else {
      pre.insert(p[i]);
    }
  }
  cout<<tot<<endl;
  return 0;
}
