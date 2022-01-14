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
int n, m, q, k;
int t;
int a[N];
bool dp[N];
string s;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    map<string, pair<int,int>> mp;
    mp.clear();
    for (int i = 1; i <= n; ++i) {
      cin>>s;
      for (int j = 0; j < m; ++j) {
        if (j+1 < m && mp.find(s.substr(j,2))==mp.end()) {
          mp[s.substr(j,2)] = make_pair(i, j+1);
        }
        if (j+2 < m && mp.find(s.substr(j,3)) == mp.end()) {
          mp[s.substr(j,3)] = make_pair(i, j+1);
        }
      }
    }
    cin>>s;
    for (int i = 0; i <= m; ++i) {
      dp[i] = false;
    }
    dp[0] = true;
    for (int i = 0; i < m; ++i) {
      if (dp[i]) {
        if (i + 2 <= m && mp.find(s.substr(i, 2)) != mp.end()) {
          dp[i+2] = true;
        }
        if (i +3 <= m && mp.find(s.substr(i, 3)) != mp.end()) {
          dp[i+3] = true;
        }
      }
    }
    if (dp[m]) {
      vector<pair<pair<int,int>,int>> ans;
      ans.clear();
      int cur = m;
      while(cur) {
        if (cur-2>=0 && dp[cur-2]) {
          string tmp = s.substr(cur-2, 2);
          int id = mp[tmp].first;
          int st = mp[tmp].second;
          ans.push_back(make_pair(make_pair(st, st+1), id));
          cur -= 2;
        } else if (cur-3>=0 && dp[cur-3]) {
          string tmp = s.substr(cur-3, 3);
          int id = mp[tmp].first;
          int st = mp[tmp].second;
          ans.push_back(make_pair(make_pair(st, st+2), id));
          cur -= 3;
        }
      }
      reverse(ans.begin(), ans.end());
      printf("%d\n", (int)ans.size());
      for (int i = 0; i < ans.size(); ++i) {
        printf("%d %d %d\n", ans[i].first.first, ans[i].first.second, ans[i].second);
      }
    } else {
      puts("-1");
    }
  }
  return 0;
}
