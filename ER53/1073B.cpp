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
int n;
int a[N], b[N];
bool vis[N];
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
  }
  int j = 1;
  memset(vis, false, sizeof(vis));
  for (int i = 1; i <= n; ++i) {
    if (vis[b[i]]) {
      printf("%d", 0);
    } else {
      int cnt=0;
      while(a[j] != b[i]) {
        vis[a[j]] = true;
        cnt++;
        j++;
      }
      vis[a[j]] = true;
      j++;
      cnt++;
      printf("%d", cnt);
    }
    if (i < n) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
