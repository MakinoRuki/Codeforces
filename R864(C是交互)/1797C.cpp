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
#define N 1002
#define M 1502
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
    printf("? 1 1\n");
    fflush(stdout);
    int res;
    scanf("%d", &res);
    if (res == 0) {
        printf("! 1 1\n");
        fflush(stdout);
        continue;
    }
    int x=1+res;
    int y=1+res;
    if (x <= n && y <= m) {
        printf("? %d %d\n", x, y);
        fflush(stdout);
        scanf("%d", &res);
        printf("? %d %d\n", x-res, y);
        fflush(stdout);
        int res2;
        scanf("%d", &res2);
        if (res2 == 0) {
            printf("! %d %d\n", x-res, y);
        } else {
            printf("! %d %d\n", x, y-res);
        }
    } else if (y <= m) {
        printf("? %d %d\n", n, y);
        fflush(stdout);
        scanf("%d", &res);
        printf("! %d %d\n", n-res, y);
    } else {
        printf("? %d %d\n", x, m);
        fflush(stdout);
        scanf("%d", &res);
        printf("! %d %d\n", x, m-res);
    }
    fflush(stdout);
  }
  return 0;
}
