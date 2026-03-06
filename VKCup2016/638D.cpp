/* 只看邻近两个点能不能绕过它即可。 */

#include <iostream>
#include <sstream>
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
#include <stack>
#include <bitset>
#include <chrono>
#define N 1000005
#define M 110
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const ll mod3 = 1000003;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int mat[M][M][M];
bool check2(int x1, int y1, int z1, int x2, int y2, int z2, int x0, int y0, int z0) {
  if (x1 < 1 || x1 > n) return false;
  if (y1 < 1 || y1 > m) return false;
  if (z1 < 1 || z1 > k) return false;
  if (!mat[x1][y1][z1]) return false;
  if ((x1==x0) && (y1==y0) && (z1==z0)) return false;
  if ((x1+1==x2) && (y1==y2) && (z1==z2)) return true;
  if ((x1==x2) && (y1+1==y2) && (z1==z2)) return true;
  if ((x1==x2) && (y1==y2) && (z1+1==z2)) return true;
  return false;
}
bool check(int x1, int y1, int z1, int x2, int y2, int z2, int x0, int y0, int z0) {
  if (x1 < 1 || x1 > n) return false;
  if (y1 < 1 || y1 > m) return false;
  if (z1 < 1 || z1 > k) return false;
  if (x2 < 1 || x2 > n) return false;
  if (y2 < 1 || y2 > m) return false;
  if (z2 < 1 || z2 > k) return false;
  if (!mat[x1][y1][z1] || !mat[x2][y2][z2]) return false;
  if (check2(x1+1, y1, z1, x2, y2, z2, x0, y0, z0)) return false;
  if (check2(x1, y1+1, z1, x2, y2, z2, x0, y0, z0)) return false;
  if (check2(x1, y1, z1+1, x2, y2, z2, x0, y0, z0)) return false;
  return true;
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d", &n);
  // }
  memset(mat, 0, sizeof(mat));
  cin>>n>>m>>k;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      string s;
      cin>>s;
      for (int p = 1; p <= k; ++p) {
        mat[i][j][p] = s[p-1]-'0';
      }
    }
  }
  int ans=0;
  for (int i = 1; i <= n; ++i) {
    for (int j =1; j <= m; ++j) {
      for (int p = 1; p <= k; ++p) {
        if (!mat[i][j][p]) continue;
        if (check(i-1, j, p, i+1, j, p, i, j, p)) ans++;
        else if (check(i-1, j, p, i, j+1, p, i, j, p)) ans++;
        else if (check(i-1, j, p, i, j, p+1, i, j, p)) ans++;
        else if (check(i, j-1, p, i+1, j, p, i, j, p)) ans++;
        else if (check(i, j-1, p, i, j+1, p, i, j, p)) ans++;
        else if (check(i, j-1, p, i, j, p+1, i, j, p)) ans++;
        else if (check(i, j, p-1, i+1, j, p, i, j, p)) ans++;
        else if (check(i, j, p-1, i, j+1, p, i, j, p)) ans++;
        else if (check(i, j, p-1, i, j, p+1, i, j, p)) ans++;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
 
