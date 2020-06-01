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
//#include <priority_queue>
#define N 102
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m, h;
int a[N], b[N];
int c[N][N];
int res[N][N];
int main() {
  cin>>n>>m>>h;
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &c[i][j]);
    }
  }
  memset(res, 0, sizeof(res));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (c[i][j]) {
        res[i][j] = min(a[j], b[i]);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      printf("%d", res[i][j]);
      if (j < m) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
