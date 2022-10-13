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
#define N 200005
#define M 2505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int p[N];
int a[N];
int main() {
  cin>>t;
  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    int sx, sy;
    int d;
    scanf("%d%d%d%d%d", &n, &m, &sx, &sy, &d);
    if (sx - d > 1 && sy + d < m) {
      printf("%d\n", m-1+n-1);
    } else if (sx + d < n && sy - d > 1) {
      printf("%d\n", m-1+n-1);
    } else {
      puts("-1");
    }
  }
  return 0;
}
