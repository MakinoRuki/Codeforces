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
#define M 202
#define N 200
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
int b[N];
int mx[N][N];
ll dp[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = i; j <= n; ++j) {
        int res = 0;
        set<int> ss;
        ss.clear();
        for (int k = i; k <= j; ++k) {
          ss.insert(a[k]);
        }
        while(ss.find(res) != ss.end()) {
          res++;
        }
        mx[i][j] = res;
      }
    }
    ll tot=0LL;
    for (int st = 1; st <= n; ++st) {
      for (int j = 0; j <= n; ++j) {
        dp[j] = -1;
      }
      for (int j = 1; st+j-1 <= n; ++j) {
        dp[st+j-1] = mx[st][st+j-1] + 1;
      }
      for (int j = st; j <= n; ++j) {
        if (dp[j] >= 0) {
          for (int k = j+1; k <= n; ++k) {
            dp[k] = max(dp[k], dp[j] + 1+ mx[j+1][k]);
          }
        }
      }
      for (int j = st; j <= n; ++j) {
      //  cout<<"i="<<st<<" "<<j<<" "<<dp[st]<
        if (dp[j] >= 0) {
          tot += dp[j];
        }
      }
    }
    printf("%lld\n", tot);
  }
  return 0;
}
