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
int cnt[N];
int solve(int x) {
  int mx=-1,mn=10;
  while(x) {
    mx=max(mx, x%10);
    mn=min(mn, x%10);
    x/=10;
  }
  return mx-mn;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int l, r;
    scanf("%d%d", &l, &r);
    int ans=0;
    int dt=0;
    for (int i = l; i <= min(r, l+200); ++i) {
      int x=solve(i);
      if (x >= dt) {
        dt = x;
        ans = i;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
