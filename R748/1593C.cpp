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
#include <stack>
#define eps 1e-7
#define M 502
#define N 400005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int m, k, t;
int n;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 1;i <= k; ++i) {
      scanf("%d", &a[i]);
    }
    sort(a+1, a+k+1);
    int tot=0;
    ll sum = 0LL;
    for (int i = k; i >= 1; --i) {
      if (sum < a[i]) {
        tot++;
        sum += n-a[i];
      }
    }
    printf("%d\n", tot);
  }
  return 0;
}
