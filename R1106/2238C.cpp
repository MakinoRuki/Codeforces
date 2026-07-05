
#include <iostream>
#include <sstream>
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
#include <stack>
#include <bitset>
#include <chrono>
#define N 2000005
#define M 1805
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 676767677;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
int b[N];
vector<int> edges[N];
int dep[N];
ll ans;
int dfs(int u, int p, int d) {
  dep[u] = d;
  int d1=-1,d2=-1;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    int res=dfs(v, u, d+1);
    if (res > d1) {
      d2=d1, d1=res;
    } else if (res > d2) {
      d2 = res;
    }
  }
  ans++;
  if (d1 < 0 || d2 < 0) {
    if (d1 >= 0) {
      return d1;
    }
    return d;
  }
  ans += d2 - d;
  return d1;
}
int main() {
 cin>>t;
 for (int cas=1; cas<=t; ++cas) {
 //  ll x, y;
   scanf("%d", &n);
 //  string s;
   for (int i = 1; i <= n; ++i) {
     edges[i].clear();
   }
   for (int i = 2; i <= n; ++i) {
     int p;
     scanf("%d", &p);
     edges[p].push_back(i);
   }
  // ll ans=0LL;
   ans = 0LL;
   dfs(1, 0, 0);
   printf("%lld\n", ans);
 }
 return 0;
}
