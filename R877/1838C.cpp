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
#define N 1002
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int pr[N];
int ans[N][N];
int main() {
  for (int i = 1; i <= 1000; ++i) {
    pr[i] = true;
  }
  pr[1] = false;
  for (int i =2; i <= 1000; ++i) {
    if (pr[i]) {
      for (int j = i*2; j <= 1000; j += i) {
        pr[j] = false;
      }
    }
  }
  //cout<<pr[4]<<endl;
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    bool nn = pr[n];
    bool mm = pr[m];
   // cout<<nn<<" "<<mm<<endl;
    if (!nn) {
      for (int j = 1; j <= m; ++j) {
        if (j == 1) ans[1][j] = 1;
        else ans[1][j] = ans[1][j-1] + n; 
      }
      for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
          ans[i][j] = ans[i-1][j] + 1;
        }
      }
    } else if (!mm) {
      for (int i = 1; i <= n; ++i) {
        if (i == 1) ans[i][1] = 1;
        else ans[i][1] = ans[i-1][1] + m;
      }
      for (int j = 2; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) {
          ans[i][j] = ans[i][j-1] + 1;
        }
      }
    } else {
      for (int j = 1; j <= m; ++j) {
        if (j == 1) ans[1][j] = 1;
        else if (ans[1][j-1] + 2*n <= n*m-n+1) {
          ans[1][j] = ans[1][j-1] + 2*n;
        } else {
          ans[1][j] = 1+n;
        }
      }
      for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
          ans[i][j] = ans[i-1][j] + 1;
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        printf("%d ", ans[i][j]);
      }
      cout<<endl;
    }
  }
  return 0;
}
