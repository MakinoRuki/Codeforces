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
#define N 252
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, q;
string s;
int dp[N][N][N];
vector<string> cs;
int nxt[M][26];
void solve(int a, int b, int c) {
  int s1 = cs[0].size();
  int s2 = cs[1].size();
  int s3 = cs[2].size();
  for (int i = a; i <= s1; ++i) {
    for (int j = b; j <= s2; ++j) {
      for (int k = c; k <= s3; ++k) {
        dp[i][j][k] = inf;
      }
    }
  }
  for (int i = a; i <= s1; ++i) {
    for (int j = b; j <= s2; ++j) {
      for (int k = c; k <= s3; ++k) {
        if (i==0 && j == 0 && k == 0) dp[i][j][k] = -1;
        if (i && dp[i-1][j][k] < inf) {
          dp[i][j][k] = min(dp[i][j][k], nxt[dp[i-1][j][k]+1][cs[0][i-1]-'a']);
        }
        if (j && dp[i][j-1][k] < inf) {
          dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j-1][k]+1][cs[1][j-1]-'a']);
        }
        if (k && dp[i][j][k-1] < inf) {
          dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j][k-1]+1][cs[2][k-1]-'a']);
        }
      }
    }
  }
}
int main() {
  scanf("%d%d", &n, &q);
  cin>>s;
  for (int i = n; i >= 0; --i) {
    for (int j = 0; j < 26; ++j) {
      nxt[i][j] = inf;
      if (i==n) continue;
      if (s[i] == j+'a') nxt[i][j] = i;
      else nxt[i][j] = nxt[i+1][j];
    }
  }
  cs.clear();
  for (int i = 0; i < 3; ++i) {
    cs.push_back("");
  }
  solve(0, 0, 0);
  for (int i = 0; i < q; ++i) {
    string op;
    int id;
    string c;
    cin>>op;
    if (op == "+") {
      cin>>id>>c;
      cs[id-1] += c;
      if (id==1) solve(cs[id-1].size(), 0, 0);
      else if (id==2) solve(0, cs[id-1].size(), 0);
      else solve(0, 0, cs[id-1].size());
    } else {
      cin>>id;
      cs[id-1].pop_back();
    }
    if (dp[cs[0].size()][cs[1].size()][cs[2].size()] < inf) {
      cout<<"YES"<<endl;
    } else {
      cout<<"NO"<<endl;
    }
  }
  return 0;
}
