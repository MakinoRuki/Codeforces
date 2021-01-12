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
#define M 31
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, t;
int x[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &x[i]);
    }
    int cnt=0;
    sort(x+1, x+n+1);
    for (int i = 1; i <= n; ++i) {
      if (i == 1) {
        cnt++;
      } else {
        if (x[i] <= x[i-1]) {
          x[i]++;
        }
        if (x[i] != x[i-1]) {
          cnt++;
        }
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
