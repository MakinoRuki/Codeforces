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
#define N 500005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[M][M];
int b[M][M];
int main() {
  cin>>t;
  int cnt=0;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      string s;
      cin>>s;
      for (int j = 1; j <= m; ++j) {
        a[i][j] = s[j-1]-'0';
      }
    }
    for (int i = 1; i <= n; ++i) {
      string s;
      cin>>s;
      for (int j = 1; j <= m; ++j) {
        b[i][j] = s[j-1] - '0';
      }
    }
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < m; ++j) {
        int dt = (a[i][j]-b[i][j]+3)%3;
        if (dt != 0) {
          a[i][j] = (a[i][j]+dt)%3;
          a[i+1][j+1] = (a[i+1][j+1]+dt)%3;
          dt = 3-dt;
          a[i][j+1] = (a[i][j+1]+dt)%3;
          a[i+1][j] = (a[i+1][j]+dt)%3;
        }
      }
    }
    for (int i = n; i > 1; --i) {
      for (int j = m; j > 1; --j) {
        int dt = (b[i][j]-a[i][j]+3)%3;
        if (dt != 0) {
          a[i][j] = (a[i][j]+dt)%3;
          a[i-1][j-1] = (a[i-1][j-1]+dt)%3;
          dt = 3-dt;
          a[i][j-1] = (a[i][j-1]+dt)%3;
          a[i-1][j] = (a[i-1][j]+dt)%3;
        }
      }
    }
    bool ok=true;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (a[i][j] != b[i][j]) {
          ok=false;
          break;
        }
      }
    }
    if (ok) puts("YES");
    else puts("NO");
  }
  return 0;
}
