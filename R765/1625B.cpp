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
#define M 300005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q, p;
int l, r;
int t;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    map<int, vector<int>> ids;
    ids.clear();
    for (int i = 1; i <= n; ++i) {
      int x;
      scanf("%d", &x);
      ids[x].push_back(i);
    }
    int ans=-1;
    for (auto itr : ids) {
      auto v = itr.second;
      if (v.size() <= 1) {
        continue;
      }
      for (int i = 1; i < v.size(); ++i) {
        int id1 = v[i-1];
        int id2 = v[i];
        ans = max(ans, id1-1+n-id2+1);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
