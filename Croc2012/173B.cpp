/* 因为光线是直线，因此一条光线可以直接cover一整行或者一整列。
那么一个石柱(r,c)可以看成连接它所在的r行和c列，cost=1。因此把石柱所在位置和行和列连边，然后求最短路。 */

#include <iostream>
#include <sstream>
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
#include <chrono>
#define N 3000005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod1 = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 1000003;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
int mat[M][M];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int nxt[M][M][4];
int dp[2*M];
void solve() {
  for (int i = 1; i <= n+m; ++i) {
    dp[i]=inf;
  }
  dp[n]=0;
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  pq.push(make_pair(0, n));
  while(!pq.empty()) {
    auto pr = pq.top();
    pq.pop();
    int v = pr.first;
    int x = pr.second;
    if (dp[x] < v) continue;
    if (x <= n) {
      for (int j = 1; j <= m; ++j) {
        if (mat[x][j]) {
          if (dp[n+j] > dp[x] + 1) {
            dp[n+j] = dp[x]+1;
            pq.push(make_pair(dp[n+j], n+j));
          }
        }
      }
    } else {
      for (int i = 1; i <= n; ++i) {
        if (mat[i][x-n]) {
          if (dp[i] > dp[x] + 1) {
            dp[i] = dp[x] + 1;
            pq.push(make_pair(dp[i], i));
          }
        }
      }
    }
  }
}
void fastReadLine(std::string &s) {
    s.clear();
    char c = getchar();
    while (c != EOF && (c == '\n' || c == '\r' || c == ' ')) c = getchar(); // 跳过空白符
    while (c != EOF && c != '\n' && c != '\r') {
        s.push_back(c);
        c = getchar();
    }
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d", &n);
  // }
  cin>>n>>m;
  memset(nxt, -1, sizeof(nxt));
  for (int i = 1; i <= n; ++i) {
    string s;
    fastReadLine(s);
    for (int j = 1; j <= m; ++j) {
      if (s[j-1] == '.') mat[i][j]=0;
      else mat[i][j]=1;
    }
  }
  for (int i = 1; i <= n; ++i) {
    int pre=-1;
    for (int j = 1; j <= m; ++j) {
      if (mat[i][j]) {
        if (pre >= 0) {
          nxt[i][j][2] = pre;
          nxt[i][pre][3] = j;
        }
        pre = j;
      }
    }
  }
  for (int j = 1; j <= m; ++j) {
    int pre=-1;
    for (int i = 1; i <= n; ++i) {
      if (mat[i][j]) {
        if (pre >= 0) {
          nxt[i][j][0] = pre;
          nxt[pre][j][1] = i;
        }
        pre = i;
      }
    }
  }
  solve();
  int ans=dp[1];
  if (ans >= inf) puts("-1");
  else cout<<ans<<endl;
  return 0;
}
 
