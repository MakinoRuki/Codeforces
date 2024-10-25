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
#define N 500005
#define M 325
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
int dp[N][22];
int ans;
ll sum[N];
int dfs(int l, int r) {
  if (l>r) return 0;
  if (l >= r) return 1;
  int dt = r-l+1;
  int cnt=0;
  while((1<<cnt) <= dt) {
    cnt++;
  }
  cnt--;
  int id1 = dp[l][cnt];
  int id2 = dp[r-(1<<cnt)+1][cnt];
  int id =id1;
  if (a[id2] > a[id]) {
    id = id2;
  }
  int res1=dfs(l, id-1);
  int res2=dfs(id+1, r);
  int res=1;
  if (sum[id-1]-sum[l-1]>=a[id]) {
    res += res1;
  }
  if (sum[r]-sum[id]>=a[id]) {
    res += res2;
  }
  return res;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x;
    scanf("%d%d", &n, &x);
    sum[0]=0LL;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      sum[i] = sum[i-1]+a[i];
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= 20; ++j) {
        dp[i][j] = -1;
      }
    }
    for (int j = 0; j <= 20; ++j) {
      for (int i = 1; i <= n; ++i) {
        if (j == 0) dp[i][j] = i;
        else if (i+(1<<j)-1<=n) {
          int id1 = dp[i][j-1];
          int id2 = dp[i+(1<<(j-1))][j-1];
          if (a[id1] > a[id2]) {
            dp[i][j] = id1;
          } else {
            dp[i][j] = id2;
          }
        }
      }
    }
    ans = dfs(1, n);
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

