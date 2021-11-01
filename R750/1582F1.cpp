#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, h;
ll k;
int q;
int a[N];
int b[N];
int id[N][502];
int dp[1000];
bool vis[N];
int main() {
  cin>>n;
  for (int i =1 ; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
//  memset(id, -1, sizeof(id));
  memset(vis, false, sizeof(vis));
  //memset(dp, false, sizeof(dp));
  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 0; j <= 500; ++j) {
  //     id[i][j]= id[i-1][j];
  //   }
  //   id[i][a[i]] = i;
  // }
  // for (int i = 0; i <= 500; ++i) {
  //   for (int j = 0; j <= 512; ++j) {

  //   }
  // }
  for (int i = 0; i <= 600; ++i) {
    dp[i] = 701;
  }
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= 600; ++j) {
      if ((j^a[i]) <= 600 && dp[j ^ a[i]] < a[i]) {
      //  if (j == 700) cout<<j<<" "<<a[i]<<" "<<(j^a[i])<<" "<<dp[j^a[i]]<<endl;
        dp[j] = min(dp[j], a[i]);
      }
    }
    //dp[a[i]] = min(dp[a[i]], a[i]);
  }
  vector<int> ans;
  ans.clear();
  for (int i = 0; i <= 600; ++i) {
    if (dp[i] < 701) {
      ans.push_back(i);
    }
  }
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < ans.size(); ++i) {
    printf("%d", ans[i]);
    if (i < ans.size()-1) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
