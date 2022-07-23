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
#define N 3005
#define M 300005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
// a[N];
int a[5];
bool ok[5];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    //scanf("%d%d", &n, &k);
    int x;
    scanf("%d%d%d%d", &x, &a[1], &a[2], &a[3]);
    memset(ok, false, sizeof(ok));
    int cur=x;
    while(cur) {
      if (!ok[cur]) {
        ok[cur] = true;
        cur = a[cur];
      } else {
        break;
      }
    }
    if (ok[1] && ok[2] && ok[3]) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}
