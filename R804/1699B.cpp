#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define eps 1e-8
#define N 60
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N][N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int j = 1; j <= m; ++j) {
      if (j == 1) a[1][j] = 0;
      else {
        if (j % 2 == 0) a[1][j] = !a[1][j-1];
        else a[1][j] = a[1][j-1];
      }
    }
    for (int i= 2; i <= n; ++i) {
      if (i % 2 == 0) {
        for (int j = 1; j <= m; ++j) {
          a[i][j] = !a[i-1][j];
        }
      } else {
        for (int j = 1; j <= m; ++j) {
          a[i][j] = a[i-1][j];
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        printf("%d", a[i][j]);
        if (j < m) cout<<" ";
        else cout<<endl;
      }
    }
  }
  return 0;
}
