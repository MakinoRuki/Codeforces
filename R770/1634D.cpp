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
#define M 500005
#define N 502
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N][N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int x = 1, y = 2;
    int id = 0;
    int cur=0;
    bool ok=true;
    for (int i = 3; i <= n; ++i) {
      printf("? %d %d %d\n", x, y, i);
      fflush(stdout);
      int res;
      scanf("%d", &res);
      if (id == 0) {
        id = i;
        cur = res;
      } else if (res > cur) {
        id = i;
        cur = res;
        ok=false;
      } else if (res < cur) {
        ok=false;
      }
    }
    // if (ok) {
    //   printf("! %d %d\n", x, y);
    //   fflush(stdout);
    // } else {
      int id2 = 0;
      int z = x;
      int cur2 = cur;
      bool found=false;
      for (int i = 3;  i<= n; ++i) {
        if (i == id) {
          continue;
        }
        printf("? %d %d %d\n", id, z, i);
        fflush(stdout);
        int res;
        scanf("%d", &res);
        if (res > cur2) {
          cur2 = res;
          id2 = i;
        } else if (res < cur) {
          found=true;
        }
      }
      if (cur2 > cur) {
        printf("! %d %d\n", id, id2);
      } else if (!found) {
        printf("! %d %d\n", id, z);
      } else if (ok) {
        printf("! %d %d\n", x, y);
      } else {
        printf("! %d %d\n", id, y);
      }
      fflush(stdout);
    }
  return 0;
}
