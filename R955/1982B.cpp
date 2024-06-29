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
#define N 500005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x,y;
    scanf("%d%d%d", &x, &y, &k);
    int cnt=0;
    while(cnt < k) {
      if (x == 0) {
        x = (k-cnt)%y;
        break;
      }
      if ( x== 1) {
        x += (k-cnt)%(y-1);
        break;
      }
      int r = y - x % y;
      int dt = min(r, k-cnt);
      x += dt;
      cnt += dt;
      while((x%y) == 0) {
        x/=y;
      }
    }
    printf("%d\n", x);
  }
  return 0;
}
