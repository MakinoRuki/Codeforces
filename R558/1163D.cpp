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
#define N 1002
#define M 52
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
string c;
int n;
string s,t;
int dp[N][M][M];
int nxt1[N], nxt2[N];
void getnxt(string& ss, int* nxt) {
  for (int i = 0; i <= ss.size(); ++i) {
    nxt[i] = -1;
  }
  for (int i = 1; i < ss.size(); ++i) {
    int j = nxt[i-1];
    while(j >= 0 && ss[j+1] != ss[i]) {
      j = nxt[j];
    }
    if (ss[j+1] == ss[i]) nxt[i] = j+1;
    else nxt[i] = -1;
  }
}
int getid(string& ss, int cur, int x, int* nxt) {
  if (ss[cur] - 'a' == x) {
    if (cur+1 < ss.size()) return cur+1;
    return nxt[ss.size()-1]+1;
  }
  cur--;
  if (cur<0) return 0;
  while(cur>=0 && ss[cur+1]-'a' != x) {
    cur=nxt[cur];
  }
  if (cur>=0) {
    return cur+2;
  }
  if (ss[cur+1] - 'a' == x) return cur+2;
  return 0;
}
int main() {
  cin>>c>>s>>t;
  n = c.size();
  getnxt(s, nxt1);
  getnxt(t, nxt2);
  // for (int i = 0; i < s.size(); ++i) {
  //   cout<<i<<" "<<nxt1[i]<<endl;
  // }
  // for (int i = 0; i < t.size(); ++i) {
  //   cout<<i<<" "<<nxt2[i]<<endl;
  // }
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= s.size(); ++j) {
      for (int k = 0; k <= t.size(); ++k) {
        dp[i][j][k] = -1000000000;
      }
    }
  }
  dp[0][0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < s.size(); ++j) {
      for (int k = 0; k < t.size(); ++k) {
        if (dp[i][j][k] > -1000000000) {
          if (c[i] == '*') {
            for (int x = 0; x < 26; ++x) {
              int det=0;
              if (j == s.size()-1 && x+'a' == s.back()) det++;
              if (k == t.size()-1 && x+'a' == t.back()) det--;
              int j2=getid(s, j, x, nxt1);
              int k2=getid(t, k, x, nxt2);
              dp[i+1][j2][k2] = max(dp[i+1][j2][k2], dp[i][j][k]+det);
            }
          } else {
            int det=0;
            int x=c[i]-'a';
            if (j == s.size()-1 && x+'a' == s.back()) det++;
            if (k == t.size()-1 && x+'a' == t.back()) det--;
            int j2=getid(s, j, x, nxt1);
            int k2=getid(t, k, x, nxt2);
            dp[i+1][j2][k2] = max(dp[i+1][j2][k2], dp[i][j][k]+det);
          }
        }
      }
    }
  }
  int ans=-1000000000;
  for (int j = 0; j < s.size(); ++j) {
    for (int k = 0; k < t.size(); ++k) {
      ans = max(ans, dp[n][j][k]);
    }
  }
  cout<<ans<<endl;
  return 0;
}
