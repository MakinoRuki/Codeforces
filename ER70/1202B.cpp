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
#define M 12
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
string s;
int dp[M][M][M][M];
void bfs(int x, int y, int a) {
  dp[x][y][a][a] = 0;
  queue<int> q;
  q.push(a);
  int cnt=0;
  while(!q.empty()) {
    cnt++;
  //  if (cnt > 2000) break;
    int cur = q.front();
    q.pop();
    if (dp[x][y][a][(cur+x)%10] >= inf) {
      dp[x][y][a][(cur+x)%10] = dp[x][y][a][cur] + 1;
      q.push((cur+x)%10);
    }
    if (dp[x][y][a][(cur+y)%10] >= inf) {
      dp[x][y][a][(cur+y)%10] = dp[x][y][a][cur]+1;
      q.push((cur+y)%10);
    }
  }
}
int main() {
  for (int x = 0; x <= 9; ++x) {
    for (int y = 0; y <= 9; ++y) {
      for (int a = 0; a < 10; ++a) {
        for (int b = 0; b < 10; ++b) {
          dp[x][y][a][b] = inf;
        }
        bfs(x, y, a);
      }
    }
  }
  for (int x = 0; x < 10; ++x) {
    for (int y = 0; y < 10; ++y) {
      for (int a = 0; a < 10; ++a) {
        dp[x][y][a][a] = inf;
        if (x == 0 || y == 0) {
          dp[x][y][a][a] = 0;
          continue;
        }
        int tmp=inf;
        for (int d = 0; d < 10; ++d) {
          if (a != d && (((d+x)%10==a)||((d+y)%10==a))) {
            if (dp[x][y][a][d] < inf) {
              tmp = min(tmp, dp[x][y][a][d]);
            }
          }
        }
        if (tmp < inf) dp[x][y][a][a] = tmp+1;
      }
    }
  }
//  cout<<dp[0][1][0][8]<<" "<<dp[0][1][8][4]<<" "<<dp[0][1][4][0]<<endl;
  cin>>s;
  for (int x = 0; x < 10; ++x) {
    for (int y = 0; y < 10; ++y) {
      int ans = 0;
      for (int k = 1; k < s.size(); ++k) {
        if (s[k] == s[k-1]) {
          if (x==0 || y == 0) {
            continue;
          }
          if (dp[x][y][s[k]-'0'][s[k]-'0']>=inf) {
            ans=-1;
            break;
          }
          ans += dp[x][y][s[k]-'0'][s[k]-'0']-1;
          continue;
        }
        if (dp[x][y][s[k-1]-'0'][s[k]-'0'] >= inf) {
          ans=-1;
          break;
        }
        ans += (dp[x][y][s[k-1]-'0'][s[k]-'0']-1);
      }
      printf("%d", ans);
      if (y < 9) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
