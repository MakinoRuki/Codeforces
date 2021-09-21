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
#define M 21
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
string s;
int a[N], b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
    }
    vector<pair<int,int>> rk;
    rk.clear();
    for (int i = 1; i <= n; ++i) {
      rk.push_back(make_pair(b[i], i-1));
    }
    sort(rk.begin(), rk.end());
    for (int i = n-2; i >= 0; --i) {
      rk[i].second = min(rk[i].second, rk[i+1].second);
    }
    int ans = 2*n;
    for (int i = 1; i <= n; ++i) {
      auto id = upper_bound(rk.begin(), rk.end(), make_pair(a[i], 0)) - rk.begin();
      ans = min(ans, i-1 + rk[id].second);
    }
    printf("%d\n", ans);
  }
  return 0;
}
