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
#define N 300005
#define M 20
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[M][M];
int b[M][M];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &m, &k);
    if (k < n-1+m-1) {
      puts("NO");
      continue;
    }
    int dt = k-(n-1+m-1);
    if (dt %2) {
      puts("NO");
      continue;
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        a[i][j]=1;
        b[i][j]=1;
      }
    }
    for (int i = 1; i < m; ++i) {
      if (i%2) a[1][i] = 1;
      else a[1][i]=0;
    }
    for (int i = 1; i < n; ++i) {
      if (i == 1) {
        b[i][1]=b[i][2]=0;
      }
      if (i%2) {
        if (m%2) b[i][m]=1;
        else b[i][m]=0;
      } else {
        if (m%2) b[i][m]=0;
        else b[i][m]=1;
      }
    }
    a[2][1]=1;
    a[n-1][m-1] = !b[n-2][m];
    b[n-1][m-1] = !a[n-1][m-1];
    a[n][m-1] = !b[n-1][m-1];
    puts("YES");
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j < m; ++j) {
        if (a[i][j]) cout<<"R ";
        else cout<<"B ";
      }
      cout<<endl;
    }
    for (int i = 1; i < n; ++i) {
      for (int j= 1; j <= m; ++j) {
        if (b[i][j]) cout<<"R ";
        else cout<<"B ";
      }
      cout<<endl;
    }
  }
  return 0;
}
