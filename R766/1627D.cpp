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
#define M 52
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
int q;
int a[N];
bool vis[N];
int getgcd(int x, int y) {
  return y == 0 ? x : getgcd(y, x%y);
}
int main() {
  memset(vis, false, sizeof(vis));
  cin>>n;
  int mx=0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
   // a[i] = (i > 1 ? a[i-1]+10 : i);
    vis[a[i]] = true;
    mx = max(mx, a[i]);
  }
  // for (int i = 1; i <= n; ++i) {
  //   cout<<a[i]<<" ";
  // }
  // cout<<endl;
  int ans=0;
  for (int i = 1; i <= mx; ++i) {
    if (!vis[i]) {
      int g = -1;
      for (int j = 2*i; j <= mx; j += i) {
        if (vis[j]) {
          g = (g < 0 ? j : getgcd(g, j));
        }
      }
      if (g == i) {
        ans++;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
