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
#define M 52
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, h;
int k;
int q;
int mat[4][4];
bool check(int x1, int y1, int x2, int y2) {
  if (mat[x1][y1] == 1 && mat[x2][y2] == -1) {
    return true;
  }
  if (mat[x1][y1] == -1 && mat[x2][y2] == 1) {
    return true;
  }
  return false;
}
int main() {
  memset(mat, -1, sizeof(mat));
  for (int i = 0; i < 4; ++i) {
    string s;
    cin>>s;
    for (int j = 0; j < 4; ++j) {
      if (s[j] == 'x') mat[i][j] = 1;
      else if (s[j] == 'o') mat[i][j] = 0;
    }
  }
  bool ok = false;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (mat[i][j] == 1) {
        if (i-1>=0 && i+1<4 && check(i-1, j, i+1, j)) {
          ok = true;
        }
        if (j-1>=0 && j+1<4 && check(i, j-1, i, j+1)) {
          ok = true;
        }
        if (i-1>=0 && j-1>=0 && i+1<4&& j+1<4 && check(i-1,j-1, i+1, j+1)) {
          ok = true;
        }
        if (i-1>=0 && j+1<4 && i+1<4 && j-1>=0 && check(i-1, j+1, i+1, j-1)) {
          ok = true;
        }
      } else if (mat[i][j] == -1) {
        if (i-1>=0 && i+1<4 && mat[i-1][j] == 1 && mat[i+1][j] == 1) {
          ok = true;
        }
        if (j-1>=0 && j+1<4 && mat[i][j-1] == 1 && mat[i][j+1] == 1) {
          ok = true;
        }
        if (i-1>=0 && j-1>=0 && i+1<4&& j+1<4 && mat[i-1][j-1] == 1 && mat[i+1][j+1] == 1) {
          ok = true;
        }
        if (i-1>=0 && j+1<4 && i+1<4 && j-1>=0 && mat[i-1][j+1] == 1 && mat[i+1][j-1] == 1) {
          ok = true;
        }
      }
    }
  }
  if (ok) puts("YES");
  else puts("NO");
  return 0;
}
