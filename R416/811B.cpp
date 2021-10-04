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
#define M 105
#define N 20005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n, m;
int p[N];
int idx[N];
int main() {
  cin>>n>>m;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &p[i]);
    idx[p[i]] = i;
  }
  while(m-->0) {
    int l, r, x;
    scanf("%d%d%d", &l, &r, &x);
    if (x < l || x > r) {
      puts("Yes");
    } else {
      int cnt=0;
      for (int i = l; i <= r; ++i) {
        if (p[i] < p[x]) {
          cnt++;
        }
      }
      if (l+cnt != x) {
        puts("No");
      } else {
        puts("Yes");
      }
    }
  }
  return 0;
}
