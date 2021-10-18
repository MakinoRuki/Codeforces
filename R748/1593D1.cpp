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
#include <stack>
#define eps 1e-7
#define M 502
#define N 400005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int m, k, t;
int n;
int a[N];
ll getgcd(ll x, ll y) {
  return y == 0 ? x : getgcd(y, x%y);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1;i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    vector<int> ds;
    ds.clear();
    for (int i = 1; i <= n; ++i) {
      for (int j = i+1; j <= n; ++j) {
        ds.push_back(abs(a[i] - a[j]));
      }
    }
    sort(ds.begin(), ds.end());
    if (ds[0] == 0 && ds.back() == 0) {
      puts("-1");
    } else {
      ll g = ds[0];
      for (int i = 1; i < ds.size(); ++i) {
        g = getgcd(g, (ll)ds[i]);
      }
      printf("%lld\n", g);
    }
  }
  return 0;
}
