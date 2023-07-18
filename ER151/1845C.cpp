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
#define M 12
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
bool dp[M][N];
int nxt[N][M];
int dx[M];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    string s;
    cin>>s;
    n = (int)s.size();
    for (int i = 0; i < 10; ++i) {
      dx[i] = n+1;
    }
    for (int i = n; i >= 0; --i) {
      for (int j = 0; j < 10; ++j) {
        nxt[i][j] = dx[j];
      }
      if (i > 0) dx[s[i-1]-'0'] = i;
    }

    scanf("%d", &m);
    string l, r;
    cin>>l>>r;
   // cout<<"nxt="<<nxt[5][0]<<endl;
    for (int i = 0; i <= m; ++i) {
      for (int j = 0; j <= n+2; ++j) {
        dp[i][j] = false;
      }
    }
    dp[0][0] = true;
    bool ok=false;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j <= n; ++j) {
        if (dp[i][j]) {
          for (int d = l[i]-'0'; d <= r[i]-'0'; ++d) {
            if (nxt[j][d] >= n+1) {
              ok=true;
              break;
            }
            dp[i+1][nxt[j][d]] = true;
          }
        }
        if (ok) break;
      }
      if (ok) break;
    }
    if (ok) puts("YES");
    else puts("NO");
  }
  return 0;
}
