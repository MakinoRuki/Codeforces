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
#define N 360
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int b[N];
int a[N][N];
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
  }
  for (int i = 1; i <= n; ++i) {
    a[i][i] = b[i];
    int d = i-1;
    for (int j = i-1; j >= 1; --j) {
      a[i][j] = (a[i][j+1] - d+n) % n;
    }
    for (int j = i+1; j <= n; ++j) {
      a[i][j] = (a[i][j-1] + d)%n;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j= 1; j <= n; ++j) {
      printf("%d ", a[i][j]);
    }
    cout<<endl;
  }
  return 0;
}
