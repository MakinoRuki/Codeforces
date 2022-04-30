#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <list>
#include <random>
#define N 40010
#define M 502
#define inf 1000000000
using namespace std;
typedef long long ll;
const int mod = 1000000007;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
bool check(int x) {
  int res=0;
  int x2=x;
  while(x2) {
    res=res*10+x2%10;
    x2/=10;
  }
  return res==x;
}
vector<int> ns;
int dp[N][M];
int sum[N][M];
int main() {
  ns.clear();
  for (int i = 1; i <= 40000; ++i) {
    if (check(i)) {
      //cout<<i<<endl;
      ns.push_back(i);
    }
  }
  memset(dp, 0, sizeof(dp));
  memset(sum, 0, sizeof(sum));
  for (int i = 1; i <= 40000; ++i) {
    for (int j = 0; j < ns.size(); ++j) {
      if (i - ns[j] < 0) break;
      if (i - ns[j] == 0) dp[i][j] = 1;
      else dp[i][j] = (dp[i][j] + sum[i-ns[j]][j]) % mod;
    }
    for (int j = ns.size()-1; j >=0; --j) {
      sum[i][j] = (sum[i][j+1] + dp[i][j]) % mod;
    }
  }

  cin>>t;
  for (int cas=1;cas<=t; ++cas) {
    scanf("%d", &n);
    int tot=0;
    for (int j = 0; j < ns.size(); ++j) {
      tot = (tot + dp[n][j]) % mod;
    }
    printf("%d\n", tot);
  }
  
  return 0;
}
