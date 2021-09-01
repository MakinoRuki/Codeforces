#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int t;
int a[N];
int getres(int sp) {
  int res=0;
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] % 2 == sp) {
      if (sum < 0) {
        res += abs(sum);
      }
      sum++;
    } else {
      if (sum > 1) {
        res += sum-1;
      }
      sum--;
    }
  }
  return res;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    int on = 0, en = 0;
    for (int i = 1; i <= n; ++i) {
      if (a[i] % 2) on++;
      else en++;
    }
    if (abs(on-en) > 1) {
      puts("-1");
    } else {
      int ans=0;
      if (en > on) {
        ans = getres(0);
      } else if (en < on) {
        ans = getres(1);
      } else {
        ans = min(getres(0), getres(1));
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
