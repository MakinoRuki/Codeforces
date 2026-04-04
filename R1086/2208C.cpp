
#include <iostream>
#include <sstream>
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
#include <stack>
#include <bitset>
#include <chrono>
#define N 2000005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 1000003;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
int p[N];
double dp[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int h;
 //   int p;
  //  int x,y;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d%d", &a[i], &p[i]);
    }
    dp[n+1] = 0;
    for (int i = n; i >= 1; --i) {
      dp[i] = dp[i+1];
      double pr = (double)(100-p[i])/(double)100;
      dp[i] = max(dp[i], dp[i+1]*pr+a[i]);
    }
    double ans= dp[1];
    printf("%.10lf\n", ans);
  }
  return 0;
}

