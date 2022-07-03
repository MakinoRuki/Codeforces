#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    int tot=0;
    int pre=1;
    for (int i = 2; i <= n; ++i) {
      if (a[i] > a[pre]) {
        pre = i;
      } else {
        tot++;
        pre = i+1;
        i++;
      }
    }
    printf("%d\n", tot);
  }
  return 0;
}
