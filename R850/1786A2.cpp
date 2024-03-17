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
#define N 300005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int a0=0,a1=0,b0=0,b1=0;
    int tot=0;
    int cur=1;
    while(tot < n) {
      int dt = min(cur, n-tot);
      int n0=dt/2,n1=dt/2;
      if (dt % 2) {
        if (tot%2) {
          n1++;
        } else {
          n0++;
        }
      }
      int q = (cur-1)/2;
      int r = (cur-1)%2;
      if (q%2) {
        if (r%2) {
          a0+=n0;
          a1+=n1;
        } else {
          b0+=n0;
          b1+=n1;
        }
      } else {
        if (r%2) {
          b0+=n0;
          b1+=n1;
        } else {
          a0+=n0;
          a1+=n1;
        }
      }
      tot += dt;
      cur++;
    }
    printf("%d %d %d %d\n", a0, a1, b0, b1);
  }
  return 0;
}
