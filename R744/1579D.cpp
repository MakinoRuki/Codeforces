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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n, m, k;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<pair<int,int>> rk;
    rk.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      rk.push_back(make_pair(a[i], i));
    }
    sort(rk.begin(), rk.end());
    vector<pair<int,int>> ans;
    ans.clear();
    int sum=0;
    for (int i = 0; i < rk.size()-1; ++i) {
      sum += rk[i].first;
    }
    if (sum < rk.back().first) {
      for (int i = 0; i < rk.size()-1; ++i) {
        for (int j = 1; j <= rk[i].first; ++j) {
          ans.push_back(make_pair(rk[i].second, rk.back().second));
          rk.back().first--;
        }
      }
    } else {
      set<pair<int,int>> ss;
      ss.clear();
      for (int i =0; i < rk.size(); ++i) {
        if (rk[i].first > 0) {
          ss.insert(make_pair(-rk[i].first, rk[i].second));
        }
      }
      while(!ss.empty()) {
        auto p1 = *ss.begin();
        ss.erase(p1);
        if (ss.empty()) break;
        auto p2 = *ss.begin();
        ss.erase(p2);
        ans.push_back(make_pair(p1.second, p2.second));
        if (-p1.first-1>0) {
          ss.insert(make_pair(p1.first+1, p1.second));
        }
        if (-p2.first-1>0) {
          ss.insert(make_pair(p2.first+1, p2.second));
        }
      }
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d %d\n", ans[i].first, ans[i].second);
    }
  }
  return 0;
}
