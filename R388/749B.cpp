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
#define M 52
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, h;
int k;
int q;
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
    
  // }
  vector<pair<int,int>> ps;
  ps.clear();
  for (int i =1; i <= 3; ++i) {
    int x,y;
    scanf("%d%d", &x, &y);
    ps.push_back(make_pair(x, y));
  }
  set<pair<int,int>> ss;
  ss.clear();
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (i == j) continue;
      int x1=(ps[i].first+ps[j].first);
      int y1=(ps[i].second+ps[j].second);
      for (int k = 0; k < 3; ++k) {
        if (k == i || k == j) continue;
        ss.insert(make_pair(x1-ps[k].first, y1-ps[k].second));
      }
    }
  }
  printf("%d\n", (int)ss.size());
  for (auto itr : ss) {
    printf("%d %d\n", itr.first, itr.second);
  }
  return 0;
}
