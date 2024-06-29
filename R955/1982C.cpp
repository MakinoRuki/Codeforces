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
#define N 500005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int l,r;
    scanf("%d%d%d", &n, &l, &r);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    int ans=0;
    int j=1;
    ll tot=0LL;
    for (int i = 1; i <= n; ++i) {
      tot += a[i];
      if (tot  < l) {
        continue;
      } else if (tot  >= l && tot  <= r) {
        ans++;
        j = i+1;
        tot = 0LL;
      } else {
        while(j <= i && tot > r) {
          tot -= a[j];
          j++;
        }
        if (j <= i && tot >=l && tot <= r) {
          ans++;
          tot = 0LL;
          j = i+1;
        } else if (j <= i && tot < l) {
          continue;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
