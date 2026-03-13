
#include <iostream>
#include <sstream>
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
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 1000003;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
ll dp[N][2];
int ans[N*2];
void dfs(int len, int kk, int l, int r) {
  if (len == 1) {
    ans[2*l-1] = l;
    ans[2*l] = l;
    return ;
  }
  if (len == 2) {
    if (kk == 2) {
      for (int i = l; i <= r; ++i) {
        ans[2*i-1]= i;
        ans[2*i] = i;
      }
    } else {
      ans[2*l-1] = l;
      ans[2*l] = r;
      ans[2*r-1] = r;
      ans[2*r] = l;
    }
    return ;
  }
  if (len == 3) {
    if (kk == 3) {
      for (int i = l; i <= r; ++i) {
        ans[2*i-1] = i;
        ans[2*i] = i;
      }
    } else if (kk == 4) {
      dfs(1, 1, l, l);
      dfs(2, 3, l+1, r);
    } else {
      for (int i = l; i <= l+1; ++i) {
        ans[2*i-1] = i;
        ans[2*i] = i+1;
      }
      ans[2*r-1] = l;
      ans[2*r] = r;
    }
    return ;
  }
  int x = len/2;
  int y = len-x;
  if (dp[x][1] + dp[y][0] >= kk) {
    dfs(x, kk-dp[y][0], l, l+x-1);
    dfs(y, dp[y][0], l+x, r);
  } else if (dp[x][1]+dp[y][1] >= kk) {
    dfs(x, dp[x][1], l, l+x-1);
    dfs(y, kk-dp[x][1], l+x, r);
  } else {
    for (int i = l; i <= r; ++i) {
      if (i == l) {
        ans[2*i-1] = l;
        ans[2*i] = l+1;
      } else if (i == r) {
        ans[2*i-1] = r-1;
        ans[2*i] = r;
      } else {
        ans[2*i-1] = i+1;
        ans[2*i] = i-1;
      }
    }
  }
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  dp[1][0] = dp[1][1] = 1;
  dp[2][0] = 2;
  dp[2][1] = 3;
  dp[3][0] = 3;
  dp[3][1] = 5;
  for (int i = 4; i < N; ++i) {
    int x = i/2;
    int y = i-x;
    dp[i][0] = dp[x][0]+dp[y][0];
    dp[i][1] = dp[x][1] + dp[y][1]+1;
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int h;
    int x,y;
    scanf("%d%d", &n, &k);
    if (k < dp[n][0] || k > dp[n][1]) {
      puts("No");
      continue;
    }
    puts("Yes");
    dfs(n, k, 1, n);
    for (int i = 1; i <= 2*n; ++i) {
      printf("%d ", ans[i]);
    }
    cout<<endl;
  }
  return 0;
}

