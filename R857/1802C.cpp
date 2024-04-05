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
ll a[210][210];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    ll x = 0LL;
    ll y = 0LL;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        a[i][j] = (x<<8)+j-1;
      }
      x++;
    }
    printf("%d\n", n*m);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        printf("%lld ", a[i][j]);
      }
      cout<<endl;
    }
  }
  return 0;
}
