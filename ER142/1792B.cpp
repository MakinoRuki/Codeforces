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
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x,y,z,w;
    scanf("%d%d%d%d", &x, &y, &z, &w);
    int ans = x;
    if (x == 0) {
      puts("1");
      continue;
    }
    ans += min(y, z) * 2;
    int cur = x;
    int dt = max(y, z) - min(y,z);
    if(cur < dt) {
      ans += cur+1;
      printf("%d\n", ans);
      continue;
    }
    cur -= dt;
    ans += dt;
    if (cur < w) {
      ans += cur+1;
    } else {
      ans += w;
    }
    printf("%d\n", ans);
  }
  return 0;
}
