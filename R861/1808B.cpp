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
#include <list>
#define N 1000005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int cnt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    vector<vector<int>> c;
    c.clear();
    for (int i = 1; i <= n; ++i) {
      vector<int> v;
      v.clear();
      for (int j = 1; j <= m; ++j) {
        int x;
        scanf("%d", &x);
        v.push_back(x);
      }
      c.push_back(v);
    }
    ll tot=0LL;
    ll sum=0LL;
    for (int j = 0; j < m; ++j) {
      sum=0LL;
      vector<ll> tmp;
      tmp.clear();
      for (int i = 0; i < n; ++i) {
        sum += c[i][j];
        tmp.push_back(c[i][j]);
      }
      sort(tmp.begin(), tmp.end());
      ll cur=0LL;
      for (int i = 0; i < n; ++i) {
        tot += tmp[i]*(ll)i - cur;
        cur += tmp[i];
        tot += (sum - cur) - (ll)(n-1-i)*tmp[i];
      }
    }
    printf("%lld\n", tot/2);
  }
  return 0;
}
