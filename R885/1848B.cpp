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
#define N 500005
#define M 15
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
vector<int> c[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; ++i) {
      c[i].clear();
      c[i].push_back(0);
    }
    for (int i = 1; i <= n; ++i) {
      int x;
      scanf("%d", &x);
      c[x].push_back(i);
    }
    for (int i = 1; i <= k; ++i) {
      c[i].push_back(n+1);
    }
    int ans=inf;
    for (int i = 1; i <= k; ++i) {
      int mx=-1, mx2=-1;
      for (int j = 1; j < c[i].size(); ++j) {
        int dt=c[i][j]-c[i][j-1]-1;
        if (dt >= mx) {
          mx2=mx;
          mx=dt;
        } else if (dt >= mx2) {
          mx2 = dt;
        }
      }
      ans=min(ans, max(mx2, mx/2));
    }
    printf("%d\n", ans);
  }
  return 0;
}
