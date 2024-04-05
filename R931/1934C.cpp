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
int dp[40];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    printf("? %d %d\n", 1, 1);
    fflush(stdout);
    int d1,d2,d3,d4;
    scanf("%d", &d1);
    printf("? %d %d\n", 1, m);
    fflush(stdout);
    scanf("%d", &d2);
    if (d1+d2-m+3 > 0 && ((d1+d2-m+3)%2)==0) {
      int x=(d1+d2-m+3)/2;
      int y=d1+2-x;
      if (x>=1 && x<=n && y>=1&&y<=m) {
        printf("? %d %d\n", x, y);
        fflush(stdout);
        scanf("%d", &d3);
        if (d3 == 0) {
          printf("! %d %d\n", x, y);
          fflush(stdout);
        } else {
          printf("? %d %d\n", n, 1);
          fflush(stdout);
          scanf("%d", &d4);
          y=(d1+d4-n+3)/2;
          x=d1+2-y;
          printf("! %d %d\n", x, y);
          fflush(stdout);
        }
      } else {
        printf("? %d %d\n", n, 1);
        fflush(stdout);
        scanf("%d", &d4);
        int y=(d1+d4-n+3)/2;
        int x=d1+2-y;
        printf("! %d %d\n", x, y);
        fflush(stdout);
      }
    } else {
      printf("? %d %d\n", n, 1);
      fflush(stdout);
      scanf("%d", &d4);
      int y=(d1+d4-n+3)/2;
      int x=d1+2-y;
      printf("! %d %d\n", x, y);
      fflush(stdout);
    }
  }
  return 0;
}
