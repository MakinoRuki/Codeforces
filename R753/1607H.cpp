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
int t, n, h;
int k;
int q;
int a[N], b[N];
int m[N];
map<int, vector<pair<int,int>>> gp;
vector<int> ans;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    gp.clear();
    ans.clear();
    for (int i = 1; i <= n; ++i) {
      ans.push_back(0);
      scanf("%d%d%d", &a[i], &b[i], &m[i]);
      gp[a[i]+b[i]-m[i]].push_back(make_pair(a[i], i));
    }
    int tot=0;
    for (auto itr : gp) {
      auto v = itr.second;
      sort(v.begin(), v.end());
      for (int i = 0; i < v.size(); ++i) {
        if (i == 0) {
          tot++;
          int id = v[i].second;
          if (b[id] < m[id]) {
            ans[id-1] = m[id] - b[id];
          }
        } else {
          int id = v[i].second;
          int id2 = v[i-1].second;
          if (a[id] - a[id2] + ans[id2-1] <= m[id]) {
            ans[id-1] = a[id] - (a[id2]-ans[id2-1]);
          } else {
            tot++;
            if (b[id] < m[id]) {
              ans[id-1] = m[id] - b[id];
            }
          }
        }
      }
    }
    printf("%d\n", tot);
    for (int i = 1; i <= n; ++i) {
      printf("%d %d\n", ans[i-1], m[i]-ans[i-1]);
    }
  } 
  return 0;
}
