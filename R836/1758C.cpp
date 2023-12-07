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
#define N 200005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
ll a[N];
int ans[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x;
    scanf("%d%d", &n, &x);
    if ((n % x) == 0) {
      ans[1] = x;
      ans[n] = 1;
      if (x == n) {
        for (int i = 1; i <= n; ++i) {
          if (i == 1 || i == n) {
            printf("%d ", ans[i]);
          } else {
            printf("%d ", i);
          }
        }
      } else {
        int idn = x;
        for (int i = 2; i < n; ++i) {
          if (i == x) ans[i] = n;
          else ans[i] = i;
        }
        for (int i = 2; i < n; ++i) {
          if (((i % idn) == 0) && ((n%i) == 0)) {
            swap(ans[idn], ans[i]);
            idn = i;
          }
        }
        for (int i = 1; i <= n; ++i) {
          printf("%d ", ans[i]);
        }
      }
      cout<<endl;
    } else {
      puts("-1");
    }
  }
  return 0;
}
