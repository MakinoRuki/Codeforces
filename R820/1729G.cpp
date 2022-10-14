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
#define N 502
#define M 2505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int dp[N];
ll dp2[N];
int l[N], r[N];
int main() {
  cin>>t;
  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    string s1, s2;
    cin>>s1>>s2;
    n = (int)s1.size();
    m = (int)s2.size();
    vector<pair<int,int>> sg;
    sg.clear();
    for (int i = 0; i + m - 1 <= n-1; ++i) {
      int j;
      for (j = 0; j < m; ++j) {
        if (s1[i + j] != s2[j]) {
          break;
        }
      }
      if (j >= m) {
        sg.push_back(make_pair(i, i+m-1));
      }
    }
    for (int i = 0; i <= n; ++i) {
      dp[i] = inf;
      dp2[i] = 0LL;
    }
    for (int i = 0; i < sg.size(); ++i) {
      l[i] = i;
      r[i] = i;
      for (int j = i-1; j >= 0; --j) {
        if (sg[j].second >= sg[i].first) {
          l[i] = j;
        } else {
          break;
        }
      }
      for (int j = i+1; j < sg.size(); ++j) {
        if (sg[j].first <= sg[i].second) {
          r[i] = j;
        } else {
          break;
        }
      }
    }
    dp[0] = 0;
    dp2[0] = 1LL;
    for (int i = 0; i < sg.size(); ++i) {
      for (int j = i+1; j <= sg.size(); ++j) {
        if (l[j-1] <= i) {
          if (dp[i] + 1 < dp[r[j-1]+1]) {
            dp[r[j-1]+1] = dp[i]+1;
            dp2[r[j-1]+1] = dp2[i];
          } else if (dp[i] + 1 == dp[r[j-1]+1]) {
            dp2[r[j-1]+1] = (dp2[r[j-1]+1] + dp2[i]) % mod;
          }
        }
      }
    }
    printf("%d %lld\n", dp[(int)sg.size()], dp2[(int)sg.size()]);
  }
  return 0;
}
