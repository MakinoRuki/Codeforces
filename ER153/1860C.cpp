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
#define N 300005
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int p[N];
int bit[N];
int lowbit(int x) {
  return x&(-x);
}
void update(int pos) {
  while(pos <= n) {
    bit[pos]++;
    pos += lowbit(pos);
  }
}
int query(int pos) {
  int sum=0;
  while(pos) {
    sum += bit[pos];
    pos -= lowbit(pos);
  }
  return sum;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &p[i]);
      bit[i] = 0;
    }
    int mn = 0;
    int ans=0;
    for (int i = 1; i <= n; ++i) {
      int res = query(p[i]);
      if (res == 0 && (i > 1 && mn<p[i])) {
        ans++;
      }
      if (i > 1 && mn < p[i]) {
        update(p[i]);
      }
      mn = ( i== 1 ? p[i] : min(mn, p[i]));
    }
    printf("%d\n", ans);
  }
  return 0;
}
