#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define N 300005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int bit[2][N];
int lowbit(int x) {
  return x&(-x);
}
void update(int id, int x, int v) {
  while(x <= n) {
    bit[id][x] += v;
    x += lowbit(x);
  }
}
int query(int id, int x) {
  int res=0;
  while(x) {
    res += bit[id][x];
    x -= lowbit(x);
  }
  return res;
}
int main() {
  memset(bit, 0, sizeof(bit));
  cin>>n>>q;
  map<int, int> rc, cc;
  rc.clear();
  cc.clear();
  while(q-->0) {
    int tp;
    scanf("%d", &tp);
    if (tp == 1) {
      int x,y;
      scanf("%d%d", &x, &y);
      rc[x]++;
      cc[y]++;
      if (rc[x] == 1) {
        update(0, x, 1);
      }
      if (cc[y] == 1) {
        update(1, y, 1);
      }
    } else if (tp == 2) {
      int x,y;
      scanf("%d%d", &x, &y);
      rc[x]--;
      cc[y]--;
      if (rc[x] <= 0) {
        update(0, x, -1);
      }
      if (cc[y] <= 0) {
        update(1, y, -1);
      }
    } else {
      int ax, ay, bx, by;
      scanf("%d%d%d%d", &ax, &ay, &bx, &by);
      int res1 = query(0, bx) - query(0, ax-1);
      int res2 = query(1, by) - query(1, ay-1);
      if (res1 == bx-ax+1 || res2==by-ay+1) {
        puts("Yes");
      } else {
        puts("No");
      }
    }
  }
  return 0;
}
