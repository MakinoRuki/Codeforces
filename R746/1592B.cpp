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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, k;
int d;
int a[N], b[N];
int t;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &d);
    vector<pair<int,int>> rk;
    rk.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      rk.push_back(make_pair(a[i], i));
    }
    sort(rk.begin(), rk.end());
    bool ok = true;
    for (int i = 0; i < rk.size(); ++i) {
      int id = rk[i].second;
      if (rk[i].first != a[i+1]) {
        int det1 = max(abs(n-(i+1)), abs(i));
        if (det1 < d) {
          ok=false;
          break;
        }
      }
    }
    if (ok) puts("YES");
    else puts("NO");
  }
  return 0;
}
