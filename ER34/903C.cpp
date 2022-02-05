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
#define N 5002
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
bool vis[N];
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a+1, a+n+1);
  int ans=0;
  memset(vis, false, sizeof(vis));
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      int cur = i;
      ans++;
      vis[i] = true;
      for (int j = i+1; j <= n; ++j) {
        if (!vis[j] && a[j] > a[cur]) {
          vis[j] = true;
          cur = j;
        }
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
