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
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int l, r;
int t;
string s;
bool vis[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
  //  cin>>n;
    //for (int k = 0; k < n; ++k) {
      for (int i = 0; i <= n; ++i) {
        vis[i] = false;
      }
      int res=0;
      if (k < n-1) {
        printf("%d %d\n", k, n-1);
        vis[k] = true;
        vis[n-1] = true;
        res += k & (n-1);
        if (k != 0) {
          printf("%d %d\n", 0, (n-1)^(k));
          vis[0] = true;
          vis[(n-1)^k] = true;
        }
        for (int i = 0; i < n; ++i) {
          if (!vis[i]) {
            printf("%d %d\n", i, (n-1)^i);
            vis[i] = true;
            vis[(n-1)^i] = true;
            res += i & ((n-1)^i);
          }
        }
      } else {
        if (n == 4) puts("-1");
        else {
          printf("%d %d\n", n-1, n-2);
          vis[n-1]=true;
          vis[n-2] = true;
          res += (n-1)&(n-2);
          printf("%d %d\n", 1, 3);
          vis[1] = true;
          vis[3] = true;
          res += 1 & 3;
          printf("%d %d\n", 0, (n-1)^3);
          vis[0] = true;
          vis[(n-1)^3] = true;
          for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
              printf("%d %d\n", i, (n-1)^i);
              vis[i] = true;
              vis[(n-1)^i] = true;
              res += i & ((n-1)^i);
            }
          }
        }
      }
    //  if (res != k) printf("ans=%d %d %d\n", n, k, res);
   // }
  }
  return 0;
}
