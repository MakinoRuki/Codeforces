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
int k;
int q;
int mx[N];
vector<int> ps[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
    
  // }
  memset(mx, 0, sizeof(mx));
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int a,b;
    scanf("%d%d", &a, &b);
    mx[a] = max(mx[a], b);
    ps[a].push_back(b);
  }
  set<pair<int,int>> ss;
  ss.clear();
  for (int i = 1; i <= n; ++i) {
    if (mx[i] > 0) {
      ss.insert(make_pair(-mx[i], i));
    }
  }
  cin>>q;
  while(q-->0) {
    scanf("%d", &k);
    vector<int> ids;
    ids.clear();
    for (int i = 1; i <= k; ++i) {
      int id;
      scanf("%d", &id);
      ids.push_back(id);
      if (mx[id]> 0) ss.erase(make_pair(-mx[id], id));
    }
    if (ss.empty()) {
      printf("%d %d\n", 0, 0);
    } else if (ss.size() == 1) {
      int id = (*ss.begin()).second;
      printf("%d %d\n", id, ps[id][0]);
    } else {
      int id1 = (*ss.begin()).second;
      ss.erase(ss.begin());
      int id2 = (*ss.begin()).second;
      ss.insert(make_pair(-mx[id1], id1));
      int v = upper_bound(ps[id1].begin(), ps[id1].end(), mx[id2]) - ps[id1].begin();
      v = ps[id1][v];
      printf("%d %d\n", id1, v);
    }
    for (int i = 0; i < ids.size(); ++i) {
      int id = ids[i];
      if (mx[id] > 0) ss.insert(make_pair(-mx[id], id));
    }
  }
  return 0;
}
