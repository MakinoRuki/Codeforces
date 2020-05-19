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
vector<ll> cards[N][4];
ll dp[N][11];
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    int k;
    scanf("%d", &k);
    for (int j = 1; j <= k; ++j) {
      int c;
      ll d;
      scanf("%d%lld", &c, &d);
      //if (n>1 || c==1) {
      // if (c == 1) {
      //   if (cards[i][1].size() < 3) {
      //     cards[i][1].push_back(d);
      //   } else {
      //     int ct = cards[i][1][0];
      //     int id = 0;
      //     for (int p = 1; p < 3; ++p) {
      //       if (cards[i][1][p] < ct) {
      //         ct = cards[i][1][p];
      //         id = p;
      //       }
      //     }
      //     if (ct < d) cards[i][1][id] = d;
      //   }
      // } else if (c == 2) {
      //   if (cards[i][2].empty()) {
      //     cards[i][2].push_back(d);
      //   } else {
      //     if (d > cards[i][2].back()) {
      //       cards[i][2][0] = d;
      //     }
      //   }
      // } else {
      //   if (cards[i][3].empty()) {
      //     cards[i][3].push_back(d);
      //   } else {
      //     if (d > cards[i][3].back()) {
      //       cards[i][3][0] = d;
      //     }
      //   }
      // }
      // } else {
      cards[i][c].push_back(d);
      // }
    }
    sort(cards[i][1].begin(), cards[i][1].end());
    reverse(cards[i][1].begin(), cards[i][1].end());
    sort(cards[i][2].begin(), cards[i][2].end());
    reverse(cards[i][2].begin(), cards[i][2].end());
    sort(cards[i][3].begin(), cards[i][3].end());
    reverse(cards[i][3].begin(), cards[i][3].end());
  }
//  if (n==1) cout<<cards[1][1][0]<<" "<<cards[1][1][1]<<" "<<cards[1][1][2]<<" "<<cards[1][2][0]<<" "<<cards[1][3][0]<<endl;
  // 999994808 999994082 236587752 999997180 999999773
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 10; ++j) {
      if (dp[i][j] < 0) continue;
      int nj = (j+1)%10;
      ll nd = 0;
      for (int p = 1; p <= 3; ++p) {
        if (cards[i+1][p].size() > 0) {
          nd = max(nd, cards[i+1][p][0]);
        }
      }
      if (nj == 0) nd *= 2;
      dp[i+1][nj] = max(dp[i+1][nj], dp[i][j]+nd);
      nj = (j+2)%10;
      nd = 0;
      if (cards[i+1][1].size()>=2) {
        nd = cards[i+1][1][0] + cards[i+1][1][1];
        if ((j+1)%10==0 || nj==0) {
          nd += cards[i+1][1][0];
        }
        dp[i+1][nj] = max(dp[i+1][nj], dp[i][j]+ nd);
      }
      nd = 0;
      if (cards[i+1][1].size() && cards[i+1][2].size()) {
        nd = cards[i+1][1][0] + cards[i+1][2][0];
        if ((j+1)%10 == 0 || nj == 0) {
          nd += max(cards[i+1][1][0], cards[i+1][2][0]);
        }
        dp[i+1][nj] = max(dp[i+1][nj], dp[i][j]+nd);
      }
      nj = (j+3)%10;
      nd = 0;
      if (cards[i+1][1].size() >= 3) {
        for (int p = 0; p < 3; ++p) {
          nd += cards[i+1][1][p];
        }
        if ((j+1)%10==0 || (j+2)%10==0 || (j+3)%10==0) {
          nd += cards[i+1][1][0];
        }
        dp[i+1][nj] = max(dp[i+1][nj], dp[i][j]+nd);
      }
      dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
    }
  }
  ll ans = 0LL;
  for (int i = 0; i < 10; ++i) {
    ans = max(ans, dp[n][i]);
  }
  cout<<ans<<endl;
  return 0;
}
