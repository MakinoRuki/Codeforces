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
    scanf("%d%d", &n, &m);
    int l = max(n-m, 0);
    int r = n+m;
    int res=0;
    int cur=0;
    for (int i = 30; i >= 0; --i) {
      if ((1<<i) & l) {
        res |= (1<<i);
        cur |= (1<<i);
      } else {
        int x = cur | (1<<i);
        if (x <= r) {
          res |= (1<<i);
        }
      }
    }
    printf("%d\n", res);
  }
  return 0;
}
