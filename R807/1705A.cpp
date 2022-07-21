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
#define N 200005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int h[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= 2*n; ++i) {
      scanf("%d", &h[i]);
    }
    sort(h+1, h+2*n+1);
    bool ok = true;
    for (int i =1; i <= n; ++i) {
      if (h[i+n]-h[i]<m) {
        ok=false;
        break;
      }
    }
    if (ok) puts("YES");
    else puts("NO");
  }
  return 0;
}
