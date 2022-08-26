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
#define N 200005
#define M 2505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int a[2][N];
ll b[2][N][2];
int main() {
  cin>>t;
  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 0; i < 2; ++i) {
      for (int j = 1; j <= n; ++j) {
        scanf("%d", &a[i][j]);
        //a[i][j] = rnd()%10;
        //if (i==0 && j==1) a[i][j]=0;
        //cout<<a[i][j]<<" ";
      }
     // cout<<endl;
    }
    for (int i = 0; i < 2; ++i) {
      for (int j = n; j >= 1; --j) {
        if (j == n) {
          b[i][j][0] = a[i][j]+j;
          b[i][j][1] = a[i][j]-j;
        } else {
          b[i][j][0] = max(b[i][j+1][0], (ll)a[i][j]+j);
          b[i][j][1] = max(b[i][j+1][1], (ll)a[i][j]-j);
        }
      }
    }
    ll ans = 0LL;
    for (int i = 2; i <= n; ++i) {
      ans++;
      if (ans < a[0][i]+1) {
        ans = a[0][i]+1;
      }
    }
    for (int i = n; i >= 1; --i) {
      ans++;
      if (ans < a[1][i]+1) {
        ans = a[1][i]+1;
      }
    }
    ll cur = 1;
    if (a[1][1]+1 > cur) cur = a[1][1]+1;
    for (int j = 2; j <= n; ++j) {
      if (j == n) {
        if (n % 2) {
          cur++;
          if (cur < a[0][n]+1) cur = a[0][n]+1;
          cur++;
          if (cur < a[1][n]+1) cur = a[1][n]+1;
        } else {
          cur++;
          if (cur < a[1][n]+1) cur = a[1][n]+1;
          cur++;
          if (cur < a[0][n]+1) cur = a[0][n]+1;
        }
      } else {
        if (j % 2) {
          ll dt = max(0LL, max(b[0][j][1] + j-cur, b[1][j][0] + j - 1 - 2*n-cur));
          ll v1 = cur + 2 * (n-j+1) + dt;
          ans = min(ans, v1);
          cur++;
          if (cur < a[0][j]+1) cur = a[0][j]+1;
          cur++;
          if (cur < a[1][j]+1) cur = a[1][j]+1;
        } else {
          ll dt = max(0LL, (ll)max(b[1][j][1] + j-cur, b[0][j][0]+j - 1-2*n-cur));
          ll v1 = cur + 2*(n-j+1) + dt;
          ans =min(ans, v1);
          cur++;
          if (cur < a[1][j]+1) cur = a[1][j]+1;
          cur++;
          if (cur < a[0][j]+1) cur = a[0][j]+1;
        }
      }
      //if (ans == 16) cout<<"j="<<j<<endl;
    }
    ans = min(ans, cur);
    printf("%lld\n", ans);
  }
  return 0;
}
