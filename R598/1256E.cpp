#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#define N 200005
using namespace std;
typedef long long ll;
const ll inf = 1000000000000000000LL;
int n;
int a[N];
ll dp[N];
int res[N];
int main() {
  cin>>n;
  vector<pair<int, int>> rk;
  rk.clear();
  for (int i = 0; i < n; ++i) {
    cin>>a[i];
    rk.push_back(make_pair(a[i], i));
  }
  sort(rk.begin(), rk.end());
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    dp[i] = inf;
  }
  for (int i = 3; i <= n; ++i) {
    for (int j = 3; j <= 5; ++j) {
      if (i - j >= 0) {
        if (dp[i-j] + rk[i-1].first - rk[i-j].first < dp[i]) {
          dp[i] = dp[i-j]+rk[i-1].first-rk[i-j].first;
          res[i] = j;
        }
      }
    }
  }
  int cur=n;
  int cnt=0;
  while(cur) {
    cnt++;
    cur -= res[cur];
  }
  int tcnt=cnt;
  vector<int> ans(n+1);
  cur=n;
  while(cur) {
    for (int i = 0; i < res[cur]; ++i) {
      ans[rk[cur-i-1].second] = cnt;
    }
    cur -= res[cur];
    cnt--;
  }
  cout<<dp[n]<<" "<<tcnt<<endl;
  for (int i = 0; i < n; ++i) {
    cout<<ans[i];
    if (i < n-1) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
