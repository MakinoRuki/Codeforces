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
#define N 500005
#define M 15
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
    int tot=0;
    scanf("%d", &tot);
    int ans=0;
    int cur=1;
    int pre=tot;
    for (int i = 1; i <= tot; ++i) {
      printf("- %d\n", cur);
      fflush(stdout);
      int res;
      scanf("%d", &res);
      if (res < pre) {
        ans += cur;
        cur<<=1;
        pre--;
      } else {
        int dt = res - pre;
        cur<<=(dt+1);
        ans += cur;
        cur<<=1;
        pre = res;
      }
    }
    printf("! %d\n", ans);
    fflush(stdout);
  }
  return 0;
}
