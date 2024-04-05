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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    int ans=0;
    int n0=0;
    int tot=0;
    int cnt=0;
    for (int i = 1; i <= n; ++i) {
      if (a[i] == 1) {
        cnt++;
        if (n0) {
          n0--;
        } else {
          tot++;
          ans = max(ans, tot);
        }
      } else {
        if (cnt%2) {
          n0 = tot-(cnt/2+1);
        } else {
          if (cnt>0) n0 = tot - ((cnt-2)/2+2);
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
