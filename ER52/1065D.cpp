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
int n;
int a[M][M];
int idx[M*M];
int dp[2][M*M][M*M][3];
bool check(int a1, int b1, int a2, int b2, int k) {
  if (k == 0) {
    if (abs(a1-a2)==1 && abs(b1-b2) == 2) return true;
    if (abs(a1-a2)==2 && abs(b1-b2) == 1) return true;
    return false;
  } else if (k==1) {
    if (a1+b1==a2+b2 || a1-b1==a2-b2) {
      return true;
    }
    return false;
  } else {
    if (a1==a2 || b2==b1) return true;
    return false;
  }
}
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%d", &a[i][j]);
      idx[a[i][j]] = (i-1)*n+(j-1);
    }
  }
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j <= n*n; ++j) {
      for (int j2 = 0; j2 <= n*n; ++j2) {
        for (int k = 0; k < 3; ++k) {
          dp[i][j][j2][k] = inf;
        }
      }
    }
  }
  queue<pair<pair<int,int>,int>> q;
  for (int i = 0; i < 3; ++i) {
    dp[0][1][1][i] = 0;
    dp[1][1][1][i] = 0;
    q.push(make_pair(make_pair(1,1), i));
  }
  while(!q.empty()) {
    auto pr = q.front();
    q.pop();
    int id = pr.first.first;
    int id2 = pr.first.second;
    int a1=idx[id]/n;
    int b1=idx[id]%n;
    int ty=pr.second;
    
    if (id2==n*n) continue;
    for (int k2 = 0; k2 < 3; ++k2) {
      if (k2 != ty) {
        if (dp[0][id][id2][k2] > dp[0][id][id2][ty]+1) {
          dp[0][id][id2][k2] = dp[0][id][id2][ty]+1;
          dp[1][id][id2][k2] = dp[1][id][id2][ty]+1;
          q.push(make_pair(make_pair(id, id2), k2));
        } else if (dp[0][id][id2][k2] == dp[0][id][id2][ty]+1 && dp[1][id][id2][k2]>dp[1][id][id2][ty]+1) {
          dp[1][id][id2][k2] = dp[1][id][id2][ty]+1;
          q.push(make_pair(make_pair(id, id2), k2));
        }
      }
    }
    for (int j = 1; j <= n*n; ++j) {
      int a2=idx[j]/n;
      int b2=idx[j]%n;
      if (check(a1, b1, a2, b2, ty)) {
        int id3=id2;
        if (j == id2+1) id3++;
        if (dp[0][j][id3][ty] > dp[0][id][id2][ty]+1) {
          dp[0][j][id3][ty] = dp[0][id][id2][ty]+1;
          dp[1][j][id3][ty] = dp[1][id][id2][ty];
          q.push(make_pair(make_pair(j, id3), ty));
        } else if (dp[0][j][id3][ty]==dp[0][id][id2][ty]+1 && dp[1][j][id3][ty] > dp[1][id][id2][ty]) {
          dp[1][j][id3][ty] = dp[1][id][id2][ty];
          q.push(make_pair(make_pair(j, id3), ty));
        }
      }
    }
  }
  //cout<<dp[3][0]<<" "<<dp[2][]
  int ans=inf;
  int ans2=inf;
  for (int j = 1; j <= n*n; ++j) {
    for (int i = 0; i < 3; ++i) {
      if (dp[0][j][n*n][i] >= inf) continue;
      if (dp[0][j][n*n][i] < ans) {
        ans=dp[0][j][n*n][i];
        ans2=dp[1][j][n*n][i];
      } else if (dp[0][j][n*n][i] == ans) {
        ans2=min(ans2, dp[1][j][n*n][i]);
      }
    }
  }
  cout<<ans<<" "<<ans2<<endl;
  return 0;
}
