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
#define M 21
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    sort(a+1, a+n+1);
    ll det = 0;
    int ans = 0;
    int i = n;
    while(i>=1) {
      if (a[i] - det <= 0) {
        break;
      }
      ans++;
      int j = i;
      while(j >= 1 && a[j] == a[i]) {
        j--;
      }
      i = j;
      det += m;
    }
    printf("%d\n", ans);
  }
  return 0;
}
