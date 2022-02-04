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
#define M 500005
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
int dp[N][22];
int ans[N];
int getgcd(int x, int y) {
  return y == 0 ? x : getgcd(y, x%y);
}
int check(int l, int r) {
  int len = r-l+1;
  int pw=0;
  while((1<<pw) <= len) {
    pw++;
  }
  pw--;
  return getgcd(dp[l][pw], dp[r-(1<<pw)+1][pw]);
}
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i <= 20; ++i) {
    if (i == 0) {
      for (int j = 1; j <= n; ++j) {
        dp[j][i] = a[j];
      }
    } else {
      for (int j = 1; j <= n; ++j) {
        if (j+(1<<(i-1)) <= n && dp[j][i-1] > 0 && dp[j+(1<<(i-1))][i-1]>0) {
          dp[j][i] = getgcd(dp[j][i-1], dp[j+(1<<(i-1))][i-1]);
        }
      }
    }
  }
  vector<pair<int,int>> sg;
  sg.clear();
  for (int i = 1; i <= n; ++i) {
    int l = i, r = n;
    while(l < r) {
      int mid=(l+r+1)/2;
      int x = check(i, mid);
      if (x >= mid-i+1) {
        l = mid;
      } else {
        r = mid-1;
      }
    }
    if (check(i, r) == r-i+1) {
      sg.push_back(make_pair(i, r));
    }
  }
  sort(sg.begin(), sg.end());
  memset(ans, 0, sizeof(ans));
  int cur = 0;
  while(cur < sg.size()) {
    int i;
    for (i = cur; i < sg.size(); ++i) {
      if (sg[i].first > sg[cur].second) {
        break;
      }
    }
    ans[sg[cur].second]++;
    cur = i;
  }
  int tot=0;
  for (int i = 1; i <= n; ++i) {
    tot += ans[i];
    printf("%d", tot);
    if (i < n) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
