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
#include <list>
#define N 1000005
#define M 635
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
    scanf("%d%d", &n, &k);
    int cnt=0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if ((a[i]%2) == 0) cnt++;
    }
    int mx=inf;
    for (int i = 1; i <= n; ++i) {
      int r = a[i]%k;
      mx=min(mx, (k-r+k)%k);
    }
    if (k == 4) {
      mx = min(mx, max(0, 2-cnt));
    }
    printf("%d\n", mx);
  }
  return 0;
}
