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
#define N 200005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int l, r;
int t;
string s;
int ans[N];
int par[N];
int cnt[N];
bool vis[N];
int find(int x) {
  return x==par[x] ? x : par[x] = find(par[x]);
}
int main() {
  cin>>n>>k;
  for (int i =1; i <= n; ++i) {
    par[i] = i;
    cnt[i] = 1;
    vis[i] = false;
  }
  for (int i = 1; i <= k; ++i) {
    int x,y;
    scanf("%d%d", &x, &y);
    int px = find(x);
    int py = find(y);
    vis[x] = true;
    vis[y] = true;
    if (px != py) {
      par[px] = py;
      cnt[py] += cnt[px];
    }
  }
  int ans=0;
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) continue;
    par[i] = find(i);
    if (par[i] == i) {
      ans += cnt[i] - 1;
    }
  }
  ans = k-ans;
  cout<<ans<<endl;
  return 0;
}
