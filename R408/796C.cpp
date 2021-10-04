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
#define M 12
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, k;
ll a[N];
vector<int> edges[N];
int main() {
  cin>>n;
  set<pair<ll,int>> ss;
  ss.clear();
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
    ss.insert(make_pair(a[i], i));
  }
  ll ans = (1LL<<62)-1;
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  for (int i =1 ; i <= n; ++i) {
    vector<int> vv;
    vv.clear();
    ll tmp = a[i];
    for (int j = 0; j < edges[i].size(); ++j) {
      int v = edges[i][j];
      vv.push_back(v);
      tmp = max(tmp, a[v] + 1);
      ss.erase(make_pair(a[v], v));
    }
    ss.erase(make_pair(a[i], i));
    if (!ss.empty()) {
      auto itr = *ss.rbegin();
      tmp = max(tmp, itr.first+2);
    }
    ans = min(ans, tmp);
    ss.insert(make_pair(a[i], i));
    for (int j = 0; j < vv.size(); ++j) {
      ss.insert(make_pair(a[vv[j]], vv[j]));
    }
  }
  cout<<ans<<endl;
  return 0;
}
