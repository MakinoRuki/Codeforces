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
int solve(int st) {
  int cnt=0;
  int cur=0;
  for (int i = 1; i <= n; ++i) {
    cur ^= a[i];
    if ((cur & st)==0) {
      cnt++;
      cur = 0;
    }
  }
  if (cur == 0) return cnt;
  return -1;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x;
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    int ans=-1;
    int st=0;
    for (int i = 29; i >= 0; --i) {
      if ((1<<i)&x) {
        st |= (1<<i);
        ans = max(ans, solve(st));
        st ^= (1<<i);
      } else {
        st |= (1<<i);
      }
    }
    ans = max(ans, solve(st));
    printf("%d\n", ans);
  }
  return 0;
}
