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
#define M 21
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
int c[N];
int a[N];
bool vis[N];
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &c[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  memset(vis, false, sizeof(vis));
  ll ans=0LL;
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      unordered_set<int> ss;
      ss.clear();
      ss.insert(i);
      int cur=a[i];
      bool found=false;
      while(!vis[cur]) {
        if (ss.find(cur) != ss.end()) {
          found=true;
          break;
        }
        ss.insert(cur);
        cur = a[cur];
      }
      if (found) {
        ll res = c[cur];
        int cur2=cur;
        while(true) {
          res = min(res, (ll)c[cur2]);
          vis[cur2] = true;
          cur2 = a[cur2];
          if (cur2 == cur) break;
        }
        ans += res;
      } else {
        cur = i;
        while(!vis[cur]) {
          vis[cur]=true;
          cur=a[cur];
        }
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
