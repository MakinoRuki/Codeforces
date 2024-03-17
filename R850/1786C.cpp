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
    ll sum=0LL;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      sum += (ll)a[i];
    }
    sort(a+1, a+n+1);
    ll tot=0LL;
    int cur=1;
    for (int i =1; i <= n; ++i) {
      if (a[i] <= cur) {
        tot += a[i];
      } else {
        if (cur +1 <= i) {
          cur++;
        }
        tot += cur;
      }
    }
    sum -= tot;
    printf("%lld\n", sum);
  }
  return 0;
}
