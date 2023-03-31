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
#define N 10000002
#define M 520
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int d;
int cnt[M];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= 50; ++i) {
      cnt[i]= 0;
    }
    for (int i =1 ; i <= n; ++i) {
      int l, r;
      scanf("%d%d", &l, &r);
      if (l <= k && k <= r) {
        for (int j =l; j <= r; ++j) {
          cnt[j]++;
        }
      }
    }
    bool ok = true;
    for (int i = 1; i <= 50; ++i) {
      if (i != k && cnt[i] >= cnt[k]) {
        ok=false;
      }
    }
    if (ok) puts("YES");
    else puts("NO");
  }
  return 0;
}
