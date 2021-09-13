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
int p[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int h;
    scanf("%d%d", &h, &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &p[i]);
    }
    if (n == 1) {
      puts("0");
    } else {
      int cur = p[2]+1;
      int ans=0;
      for (int i = 2; i <= n; ++i) {
        if (i == n) {
          if (cur == p[n]) {
            break;
          } else {
            if (cur > 2) {
              ans++;
            }
          }
        } else {
          if (cur == p[i]) {
            cur = p[i+1]+1;
            continue;
          }
          if (cur - p[i+1] <= 2) {
            cur = p[i+1];
          } else {
            ans++;
            cur = p[i+1]+1;
          }
        }
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
