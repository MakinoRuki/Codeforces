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
#define M 12
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
string s;
bool vis[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      vis[i] = false;
    }
    for (int i = 1; i <= m; ++i) {
      int a,b,c;
      scanf("%d%d%d", &a, &b, &c);
      vis[b]=true;
    }
    int id = 0;
    for (id = 1; id <= n; ++id) {
      if (!vis[id]) {
        break;
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (i == id) continue;
      printf("%d %d\n", id, i);
    }
  }
  return 0;
}
