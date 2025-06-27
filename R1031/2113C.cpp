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
#include <stack>
#include <bitset>
#include <chrono>
#define N 500005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
//ll a[N];
int sum[M][M];
int a[M][M];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &m, &k);
    int tot=0;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin>>s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == '.') a[i][j+1] = 0;
            else if (s[j] == '#') a[i][j+1] = -1;
            else a[i][j+1] = 1;
        }
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            sum[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
            if (a[i][j] == 1) sum[i][j]++;
        }
    }
    tot = sum[n][m];
    int ans=0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == 0) {
                int r2 = min(n, i+k-1);
                int c2 = min(m, j+k-1);
                int r1 = max(0, i-k);
                int c1 = max(0, j-k);
                int dt = sum[r2][c2] - sum[r1][c2] - sum[r2][c1] + sum[r1][c1];
                ans = max(ans, tot - dt);
            }
        }
    }
    printf("%d\n", ans);
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
