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
#include <ctime>
#define N 1050
#define M 2505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int h[N], w[N];
ll bit[N][N];
int lowbit(int x) {
  return x&(-x);
}
void update(int x, int y, int v) {
  for (int i = x; i < N; i += lowbit(i)) {
    for (int j = y; j < N; j += lowbit(j)) {
      bit[i][j] += v;
    }
  }
}
ll query(int x, int y) {
  ll tot=0;
  for (int i = x; i > 0; i -= lowbit(i)) {
    for (int j = y; j > 0; j-=lowbit(j)) {
      tot += bit[i][j];
    }
  }
  return tot;
}
int main() {
  cin>>t;
  mt19937 rnd(time(0));
  memset(bit, 0, sizeof(bit));
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
      scanf("%d%d", &h[i], &w[i]);
      update(h[i], w[i], h[i]*w[i]);
    }
   // cout<<"???"<<endl;
    for (int i = 1; i <= q; ++i) {
      int h1, w1, h2, w2;
      scanf("%d%d%d%d", &h1, &w1, &h2, &w2);
      ll res = query(h2-1, w2-1) - query(h2-1, w1) - query(h1, w2-1) + query(h1, w1);
      printf("%lld\n", res);
    }
    for (int i = 1; i <= n; ++i) {
      update(h[i], w[i], -w[i]*h[i]);
    }
  }
  return 0;
}
