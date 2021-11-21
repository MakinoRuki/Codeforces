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
#define M 200
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, h;
int k;
int q;
bool used[M];
vector<int> ids[N];
int main() {
  cin>>n>>q;
  set<pair<int,int>> ss;
  ss.clear();
  memset(used, false, sizeof(used));
  vector<ll> ans;
  ans.clear();
  for (int i = 1; i <= q; ++i) {
    int t1, k1, d1;
    scanf("%d%d%d", &t1, &k1, &d1);
    while(!ss.empty() && (*ss.begin()).first < t1) {
      auto tp = *ss.begin();
      for (int j = 0; j < ids[tp.second].size(); ++j) {
        used[ids[tp.second][j]] = false;
      }
      ss.erase(tp);
    }
    for (int j = 1; j <= n; ++j) {
      if (ids[i].size() == k1) {
        break;
      }
      if (!used[j]) {
        used[j] = true;
        ids[i].push_back(j);
      }
    }
    if (ids[i].size() < k1) {
      for (int j = 0; j < ids[i].size(); ++j) {
        used[ids[i][j]] = false;
      }
      ids[i].clear();
      ans.push_back(-1);
    } else {
      ll tot=0LL;
      for (int j = 0; j < ids[i].size(); ++j) {
        tot += ids[i][j];
      }
      ans.push_back(tot);
      ss.insert(make_pair(t1+d1-1, i));
    }
  }
  for (int i = 0; i < ans.size(); ++i) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}
