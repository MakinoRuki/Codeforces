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
#define N 4050
#define M 1000005
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
int cnt[M];
bool pr[M];
ll comb[N][N];
ll dp[2][N];
int main() {
  memset(pr, true, sizeof(pr));
  pr[1] = false;
  for (int i = 2; i < M; ++i) {
    if (pr[i]) {
      for (int j = 2 * i; j < M; j += i) {
        pr[j] = false;
      }
    }
  }
  cin>>n;
  for (int i = 0; i <= 2*n; ++i) {
    comb[i][0] = 1LL;
    for (int j = 1; j <= i; ++j) {
      comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % mod2;
    }
  }
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= 2*n; ++i) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
  }
  vector<pair<int,int>> v;
  v.clear();
  int tot=0;
  int sum=0;
  for (int i = 1; i < M; ++i) {
    if (cnt[i] > 0) {
      if (pr[i]) {
        v.push_back(make_pair(i, cnt[i]));
        tot += cnt[i];
      }
    }
  }
  if ((int)v.size() < n) {
    puts("0");
    return 0;
  }
  ll ans = 1LL;
  for (int i =1; i < M; ++i) {
    if (cnt[i] > 0) {
      if (!pr[i]) {
        ans = ans * comb[n-sum][cnt[i]] % mod2;
        sum += cnt[i];
      }
    }
  }
 // cout<<"ans="<<ans<<endl;
  memset(dp, 0LL, sizeof(dp));
  dp[0][0] = 1LL;
  m = (int)v.size();
  for (int i = 0; i < m; ++i) {
    int now = i&1;
    for (int j = 0; j <= n; ++j) {
      dp[now^1][j] = 0;
    }
    for (int j = 0; j <= n; ++j) {
      if (dp[now][j]) {
        int num = v[i].second;
        if (n-sum+j >=0 && n-sum+j<=n) dp[now^1][j] = (dp[now^1][j] + dp[now][j] * comb[n-sum+j][num] % mod2) % mod2;
        if (j+1<=n && n-sum+j>=0 && n-sum+j<=n) {
          dp[now^1][j+1] = (dp[now^1][j+1] + dp[now][j] * comb[n-sum+j][num-1] % mod2) % mod2;
        }
      }
    }
    sum += v[i].second;
  }
  ans = ans * dp[m&1][n] % mod2;
  cout<<ans<<endl;
  return 0;
}
