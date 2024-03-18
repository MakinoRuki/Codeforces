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
    set<int> ss;
    ss.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      ss.insert(a[i]);
    }
    int mex=0;
    for (mex = 0; mex <= n; ++mex) {
      if (ss.find(mex) == ss.end()) {
        break;
      }
    }
    printf("%d\n", mex);
    fflush(stdout);
    while(true) {
      int res;
      scanf("%d", &res);
      if (res == -1) break;
      printf("%d\n", res);
      fflush(stdout);
    }
  }
  return 0;
}
