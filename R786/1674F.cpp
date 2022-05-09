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
#include <list>
#include <random>
#define N 1005
#define M 502
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N][N];
int bit[N*N];
int tot;
int lowbit(int x) {
  return x&(-x);
}
void update(int p, int v){
  while(p <= n * m) {
    bit[p] += v;
    p += lowbit(p);
  }
}
int query(int p) {
  int res=0;
  while(p) {
    res += bit[p];
    p -= lowbit(p);
  }
  return res;
}
int main() {
  cin>>n>>m>>q;
  tot = 0;
  memset(bit, 0, sizeof(bit));
  memset(a, 0, sizeof(a));
  for (int i = 0; i < n; ++i) {
    string s;
    cin>>s;
    for (int j = 0; j < m; ++j) {
      if (s[j] == '*') a[i][j] = 1;
      else a[i][j] = 0;
    }
  }
  for (int j = 0; j < m; ++j) {
    for (int i = 0; i < n; ++i) {
      if (a[i][j]) {
        tot++;
        int id = j * n + i;
        update(id+1, 1);
      }
    }
  }
  while(q-->0) {
    int x,y;
    scanf("%d%d", &x, &y);
    x--, y--;
    int id = y * n + x + 1;
    if (a[x][y]) {
      a[x][y] = 0;
      update(id, -1);
      tot--;
    } else {
      a[x][y] = 1;
      update(id, 1);
      tot++;
    }
    int res = query(tot);
    printf("%d\n", tot-res);
  }
  return 0;
}
