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
#define N 502
#define M 15
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N][N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    int tot=0;
    for (int i =1; i <= n; ++i) {
      string s;
      cin>>s;
      for (int j = 1; j <= m; ++j) {
        a[i][j] = s[j-1]-'0';
        tot += a[i][j];
      }
    }
    int ans=0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (i + 1 <= n && j + 1 <= m) {
          int cnt = a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1];
          if (cnt <= 2) {
            ans=max(ans, tot);
          } else {
            ans = max(ans, tot-cnt+2);
          }
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
