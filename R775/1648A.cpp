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
#define M 202
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
vector<int> rs[N], cs[N];
int main() {
  cin>>n>>m;
  int cmx = 0;
  for (int i = 0; i < n * m; ++i) {
    scanf("%d", &a[i]);
    int r = i/m;
    int c = i % m;
    rs[a[i]].push_back(r);
    cs[a[i]].push_back(c);
    cmx = max(cmx, a[i]);
  }
  for (int i = 1; i <= cmx; ++i) {
    sort(rs[i].begin(), rs[i].end());
    sort(cs[i].begin(), cs[i].end());
  }
  ll tot = 0LL;
  for (int i = 1; i <= cmx; ++i) {
    ll sum = 0LL;
    for (int j = 0; j < rs[i].size(); ++j) {
      if (j > 0) {
        tot += rs[i][j] * (ll)j - sum;
      }
      sum += rs[i][j];
    }
    sum = 0LL;
    for (int j = 0; j < cs[i].size(); ++j) {
      if (j > 0) {
        tot += cs[i][j] * (ll)j - sum;
      }
      sum += cs[i][j];
    }
  }
  printf("%lld\n", tot);
  return 0;
}
