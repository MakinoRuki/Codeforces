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
int sum[M][M];
int getgcd(int x, int y) {
  return y == 0 ? x : getgcd(y, x%y);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int l,r;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= m; ++j) {
        sum[i][j] = 0;
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        scanf("%d", &a[i][j]);
      }
    }
    vector<string> v;
    v.clear();
    for (int i = 0; i < n; ++i) {
      string s;
      cin>>s;
      v.push_back(s);
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + v[i-1][j-1]-'0';
      }
    }
    ll s1=0,s0=0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (v[i-1][j-1] == '1') s1 += a[i][j];
        else s0 += a[i][j];
      }
    }
    int g = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (i+k-1<=n && j+k-1<=m) {
          int n1 = (sum[i+k-1][j+k-1]-sum[i-1][j+k-1]-sum[i+k-1][j-1]+sum[i-1][j-1]);
          int n0 = k*k-n1;
          int dt = abs(n0-n1);
       //   cout<<i<<" "<<j<<" "<<n1<<" "<<n0<<endl;
          g = getgcd(g, dt);
        }
      }
    }
    ll dt = abs(s1-s0);
    if (g == 0) {
      if (dt == 0) {
        puts("YES");
      } else {
        puts("NO");
      }
      continue;
    }
  //  cout<<"g="<<g<<" "<<dt<<endl;
    if (dt % g) {
      puts("NO");
    } else {
      puts("YES");
    }
  }
  return 0;
}
