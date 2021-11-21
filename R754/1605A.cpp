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
#define M 52
#define N 702
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, h;
ll k;
int q, p;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int a1,a2,a3;
    scanf("%d%d%d", &a1, &a2, &a3);
    ll ans = a1+a3-2*a2;
    ans = abs(ans);
    if (ans % 3 == 0) {
      puts("0");
    } else if (ans % 3 == 1) {
      puts("1");
    } else {
      puts("1");
    }
  }
  return 0;
}
