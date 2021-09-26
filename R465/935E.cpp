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
#define M 105
#define N 20005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n, p, m;
string s;
vector<int> edges[N];
int cnt;
int dp[2][N][M];
int ops[N];
int val[N];
int dfs(string s) {
  if (s.size() == 1) {
    val[++cnt] = s[0]-'0';
    return cnt;
  }
  int sum=0;
  int i;
  for (i = 1; i < s.size()-1; ++i) {
    if (s[i] == '(') sum++;
    else if (s[i] == ')') sum--;
    if (sum == 0 && s[i] == '?') {
      break;
    }
  }
  ++cnt;
  int id = cnt;
  edges[id].push_back(dfs(s.substr(1, i-1)));
  edges[id].push_back(dfs(s.substr(i+1, (int)s.size()-2-i)));
  ops[id]++;
  ops[id] += ops[edges[id][0]] + ops[edges[id][1]];
  return id;
}
void dfs2(int u, int num) {
  if (dp[0][u][num] < INT_MAX) {
    return ;
  }
  if (num > ops[u]) return;
  if (edges[u].empty()) {
    dp[0][u][num] = val[u];
    dp[1][u][num] = val[u];
    return ;
  }
  int v1=edges[u][0];
  int v2=edges[u][1];
  if (p <= m) {
    if (num>0) {
      for (int i = 0; i <= num-1; ++i) {
        dfs2(edges[u][0], i);
        dfs2(edges[u][1], num-1-i);
        if (dp[0][v1][i] < INT_MAX && dp[0][v2][num-1-i] < INT_MAX) {
          dp[0][u][num] = min(dp[0][u][num], dp[0][v1][i]+dp[0][v2][num-1-i]);
        }
        if (dp[1][v1][i] > INT_MIN && dp[1][v2][num-1-i] > INT_MIN) {
          dp[1][u][num] = max(dp[1][u][num], dp[1][v1][i] + dp[1][v2][num-1-i]);
        }
      }
    }
    if (ops[u]-num>0) {
      for (int i = 0; i <= num; ++i) {
        dfs2(edges[u][0], i);
        dfs2(edges[u][1], num-i);
        if (dp[0][v1][i] < INT_MAX && dp[1][v2][num-i] > INT_MIN) {
          dp[0][u][num] = min(dp[0][u][num], dp[0][v1][i]-dp[1][v2][num-i]);
        }
        if (dp[1][v1][i] > INT_MIN && dp[0][v2][num-i] < INT_MAX) {
          dp[1][u][num] = max(dp[1][u][num], dp[1][v1][i] - dp[0][v2][num-i]);
        }
      }
    }
  } else {
    if (num>0) {
      for (int i = 0; i <= num-1; ++i) {
        dfs2(edges[u][0], i);
        dfs2(edges[u][1], num-1-i);
        if (dp[0][v1][i] < INT_MAX && dp[1][v2][num-1-i] > INT_MIN) {
          dp[0][u][num] = min(dp[0][u][num], dp[0][v1][i]-dp[1][v2][num-1-i]);
        }
        if (dp[1][v1][i] > INT_MIN && dp[0][v2][num-1-i] < INT_MAX) {
          dp[1][u][num] = max(dp[1][u][num], dp[1][v1][i] - dp[0][v2][num-1-i]);
        }
      }
    }
    if (ops[u]-num>0) {
      for (int i = 0; i <= num; ++i) {
        dfs2(edges[u][0], i);
        dfs2(edges[u][1], num-i);
        if (dp[0][v1][i] < INT_MAX && dp[0][v2][num-i] < INT_MAX) {
          dp[0][u][num] = min(dp[0][u][num], dp[0][v1][i]+dp[0][v2][num-i]);
        }
        if (dp[1][v1][i] > INT_MIN && dp[1][v2][num-i] > INT_MIN) {
          dp[1][u][num] = max(dp[1][u][num], dp[1][v1][i] + dp[1][v2][num-i]);
        }
      }
    }
  }
}
int main() {
  string s;
  cnt=0;
  cin>>s;
  cin>>p>>m;
  memset(val, -1, sizeof(val));
  memset(ops, 0, sizeof(ops));
  dfs(s);
  for (int i = 1; i <= cnt; ++i) {
    for (int j = 0; j <= min(p,m); ++j) {
      dp[0][i][j] = INT_MAX;
      dp[1][i][j] = INT_MIN;
    }
  }
  dfs2(1, min(p,m));
  cout<<dp[1][1][min(p,m)]<<endl;
  return 0;
}
