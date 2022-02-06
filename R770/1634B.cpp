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
#define M 500005
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
// bool check(ll x, ll y) {
//   ll res = 0LL;
//   for (int i = 1; i <= n; ++i) {
//     res ^= a[i];
//   }
//   ll res2=x;
//   for (int i = 1; i <= n; ++i) {
//     if ((res2 ^ res)==y) return true;
//     res2 += a[i];
//     res ^= a[i];
//   }
//   if (res2 == y) return true;
//   return false;
// }
// void dfs(int x, int cur, set<int>& ss) {
//   if (cur == n+1) {
//     ss.insert(x);
//     return;
//   }
//   dfs(x+a[cur], cur+1, ss);
//   dfs(x^a[cur], cur+1, ss);
// }
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll x,y;
    scanf("%d%lld%lld", &n, &x, &y);
    ll sum=0LL;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      sum += (ll)a[i];
    }
    if ((sum%2) == 0) {
      if ((x%2) == 0) {
        if ((y%2) == 0) puts("Alice");
        else puts("Bob");
      } else {
        if ((y%2) == 0) puts("Bob");
        else puts("Alice");
      }
    } else {
      if ((x%2) == 0) {
        if ((y%2) == 0) puts("Bob");
        else puts("Alice");
      } else {
        if ((y%2) == 0) puts("Alice");
        else puts("Bob");
      }
    }
  }
  return 0;
}
