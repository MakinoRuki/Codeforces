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
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
string s;
int dp[N][3];
int main() {
  cin>>n>>s;
  if (n==1) {
    cout<<0<<endl;
    cout<<s<<endl;
    return 0;
  }
  if (n==2) {
    if (s[0]==s[1]) {
      cout<<1<<endl;
      if (s[0]=='R') s[1] = 'G';
      else if (s[0] == 'G') s[1] = 'B';
      else s[1] = 'R';
      cout<<s<<endl;
    } else {
      cout<<0<<endl;
      cout<<s<<endl;
    }
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 3; ++j) {
      dp[i][j] = n+1;
    }
  }
  vector<char> cs = {'R', 'G', 'B'};
  for (int j = 0; j < 3; ++j) {
    if (s[n-1]==cs[j]) {
      dp[n][j] = 0;
    } else {
      dp[n][j] = 1;
    }
  }
  for (int i = n; i > 1; --i) {
    for (int j = 0; j < 3; ++j) {
      for (int j2 = 0; j2 < 3; ++j2) {
        if (j != j2) {
          int det = (s[i-2] != cs[j2]);
          dp[i-1][j2] = min(dp[i-1][j2], dp[i][j]+det);
        }
      }
    }
  }
  int ans=n+1;
  for (int i = 0; i < 3; ++i) {
    ans = min(ans, dp[1][i]);
  }
  cout<<ans<<endl;
  string res="";
  int cur=ans;
  for (int i = 1; i <= n; ++i) {
    int j;
    for (j = 0; j < 3; ++j) {
      if (cs[j] != res.back() && dp[i][j] == cur) {
        break;
      }
    }
    res.push_back(cs[j]);
    if (cs[j] != s[i-1]) {
      cur--;
    }
  }
  cout<<res<<endl;
  return 0;
}
