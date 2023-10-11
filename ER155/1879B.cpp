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
int a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    ll tota=0LL, totb=0LL;
    int mna=-1, mnb=-1;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      tota += a[i];
      if (i == 1) mna = a[i];
      else mna = min(mna, a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
      totb += b[i];
      if (i == 1) mnb = b[i];
      else mnb = min(mnb, b[i]);
    }
    printf("%lld\n", min(tota+(ll)n*mnb, totb+(ll)n*mna));
  }
  return 0;
}
