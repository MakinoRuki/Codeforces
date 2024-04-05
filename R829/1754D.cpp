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
int cnt[N];
int main() {
  // i:1->n-1, sum(i*(i!))<n! ==> i*(i!)=(i+1)*(i!)-(i!)=((i+1)!)-(i!), sum=(n!)-1!.
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= m; ++i) {
      cnt[i]=0;
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      cnt[a[i]]++;
    }
    bool ok=true;
    for (int i = 1; i < m; ++i) {
      if (cnt[i] % (i+1)) {
        ok=false;
        break;
      }
      cnt[i+1] += cnt[i]/(i+1);
    }
    if (ok) puts("Yes");
    else puts("No");
  return 0;
}
