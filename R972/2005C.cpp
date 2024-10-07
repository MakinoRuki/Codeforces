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
#include <random>
#include <ctime>
#include <list>
#include <stack>
#define N 500005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
int dp[M][6];
int main() {
  cin>>t;
  vector<char> cv = {'n', 'a', 'r', 'e', 'k'};
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    vector<string> v;
    v.clear();
    for (int i = 1; i <= n; ++i) {
      string s;
      cin>>s;
      v.push_back(s);
    }
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j < 6; ++j) {
        dp[i][j] = -inf;
      }
    }
    dp[0][4] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 5; ++j) {
        if (dp[i][j] > -inf) {
          int cnt0 = 0, cnt1 = 0;
          int cur = j;
          for (int p = 0; p < v[i].size(); ++p) {
            if (v[i][p] == cv[(cur+1)%5]) {
              cnt1++;
              cur = (cur + 1) % 5;
            } else if (v[i][p] == 'n' || v[i][p] == 'a' || v[i][p] == 'r' || v[i][p] == 'e' || v[i][p] == 'k') {
              cnt0++;
            }
          }
          dp[i+1][cur] = max(dp[i+1][cur], dp[i][j] + cnt1 - cnt0);
          dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
        }
      }
    }
    //cout<<dp[1][0]<<" "<<dp[2][1]<<" "<<dp[3][2]<<" "<<dp[4][3]<<" "<<dp[5][4]<<endl;
    int ans=dp[n][4];
    for (int j = 0; j < 4; ++j) {
      ans = max(ans, dp[n][j] - 2*(j+1));
    }
    printf("%d\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

