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
#define N 105
#define M 100005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int a[N];
vector<string> ss;
int dp[N];
vector<int> pre[N];
bool ok[12][N];
bool check(int id, string& s1, int j) {
  for (int i = 0; i < ss[id].size(); ++i) {
    if (j-1+i >= s1.size() || ss[id][i] != s1[j-1+i]) {
      return false;
    }
  }
  return true;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    string s1;
    ss.clear();
    cin>>s1;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      string s2;
      cin>>s2;
      ss.push_back(s2);
    }
    memset(ok, false, sizeof(ok));
    for (int i = 0; i < n; ++i) {
      for (int j = 1; j <= s1.size(); ++j) {
        if (check(i, s1, j)) {
          ok[i][j] = true;
        }
      }
    }
    for (int i = 0; i <= s1.size(); ++i) {
      dp[i] = inf;
      pre[i].clear();
    }
    dp[0] = 0;
    for (int i = 0; i < s1.size(); ++i) {
      if (dp[i] < inf) {
        for (int j = 1; j <= i+1; ++j) {
          for (int k = 0; k < ss.size(); ++k) {
            if (ok[k][j] && j+ss[k].size()-1 > i) {
              if (dp[i]+1 < dp[j+ss[k].size()-1]) {
                dp[j+ss[k].size()-1] = min(dp[j+ss[k].size()-1], dp[i]+1);
                pre[j+ss[k].size()-1] = {i, k, j};
              }
            }
          }
        }
      }
    }
    if (dp[s1.size()] >= inf) {
      puts("-1");
    } else {
      printf("%d\n", dp[s1.size()]);
      vector<pair<int,int>> tmp;
      tmp.clear();
      int cur = s1.size();
      while(cur > 0) {
        tmp.push_back(make_pair(pre[cur][1]+1, pre[cur][2]));
        cur = pre[cur][0];
      }
      for (int i = 0; i < tmp.size(); ++i) {
        printf("%d %d\n", tmp[i].first, tmp[i].second);
      }
    }
  }
  return 0;
}
