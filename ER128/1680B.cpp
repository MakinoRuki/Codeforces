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
#define N 300005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m;
int t;
int a[6][6];
bool check(int x, int y, bool f) {
  if (!f) {
    for (int i =1; i < x; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (a[i][j]) return false;
      }
    }
    return true;
  } else {
    for (int j = 1; j < y; ++j) {
      for (int i = 1; i <= n; ++i) {
        if (a[i][j]) return false;
      }
    }
    return true;
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    memset(a, 0, sizeof(a));
    for (int i= 1; i <= n; ++i) {
      string s;
      cin>>s;
      for (int j= 1; j <= m; ++j) {
        if (s[j-1] == 'R') a[i][j] = 1; 
      }
    }
    bool found=false;
    for (int j = 1; j <= m; ++j) {
      int i;
      for (i= 1; i <= n; ++i) {
        if (a[i][j]) {
       //   cout<<"x="<<i<<" "<<j<<endl;
          if (check(i, j, 0)) {
            found=true;
            break;
          } else {
            break;
          }
        }
      }
      if (i <= n) break;
    }
    for (int i = 1; i <= n; ++i) {
      int j;
      for (j = 1; j <= m; ++j) {
        if (a[i][j]) {
      //    cout<<"y="<<i<<" "<<j<<endl;
          if (check(i, j, 1)) {
            found=true;
            break;
          } else {
            break;
          }
        }
      }
      if (j <= m) break;
    }
    if (found) puts("YES");
    else puts("NO");
  }
  return 0;
}
