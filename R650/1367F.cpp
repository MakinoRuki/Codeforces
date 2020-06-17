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
#define N 200005
#define M 100005
#define inf 1000000000
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
int a[N];
int id[N];
int cnt;
int BIT[N];
int dp[N][3];
int len;
int num1[N], num2[N];
int id0[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n;
    vector<pair<int, int>> rk;
    rk.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      rk.push_back(make_pair(a[i], i));
    }
    sort(rk.begin(), rk.end());
    cnt = 0;
    for (int i = 0; i < rk.size(); ++i) {
      if (i == 0 || rk[i].first != rk[i-1].first) {
        cnt++;
      }
      id[rk[i].second] = cnt;
    }
    for (int i = 1; i<= cnt+1; ++i) {
      num1[i] = 0;
      num2[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
      num1[id[i]]++;
    }
    int ans=n;
    for (int i = 1; i <= cnt+1; ++i) {
      dp[i][0] = dp[i][1] = 0;
      dp[i][2] = -1;
    }
    for (int i = n; i >= 1; --i) {
      //cout<<"i="<<i<<" "<<dp[id[i]]<<" "<<dp[id[i]+1]<<endl;
      num2[id[i]]++;
      dp[id[i]][0] = max(dp[id[i]][0], dp[id[i]+1][1]) + 1;
      if (num2[id[i]] == 1) {
        dp[id[i]][2] = dp[id[i]+1][1];
      }
      if (num1[id[i]] == num2[id[i]]) {
        dp[id[i]][1] = num1[id[i]] + dp[id[i]][2];
      } else {
        dp[id[i]][1] = num2[id[i]];
      }
      ans = min(ans, n-dp[id[i]][0]);
    }
    cout<<ans<<endl;
  }
  return 0;
}
