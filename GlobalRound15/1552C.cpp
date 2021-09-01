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
#define N 50005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
vector<pair<int,int>> segs;
bool check(int x, int y, int z) {
  return (z >= x && z <= y);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    segs.clear();
    set<int> ss;
    ss.clear();
    for (int i = 0; i < k; ++i) {
      int x,y;
      scanf("%d%d", &x, &y);
      segs.push_back(make_pair(x, y));
      ss.insert(x);
      ss.insert(y);
    }
    vector<int> rk;
    rk.clear();
    for (int i = 1; i <= 2*n; ++i) {
      if (ss.find(i) == ss.end()) {
        rk.push_back(i);
      }
    }
    sort(rk.begin(), rk.end());
    for (int i = 0; i < n-k; ++i) {
      segs.push_back(make_pair(rk[i], rk[i+n-k]));
    }
    int ans=0;
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
        int l1 = segs[i].first;
        int r1 = segs[i].second;
        int l2 = segs[j].first;
        int r2 = segs[j].second;
        if (l1 > r1) swap(l1, r1);
        if (check(l1, r1, l2) && !check(l1, r1, r2)) {
          ans++;
        } else if (!check(l1, r1, l2) && check(l1, r1, r2)) {
          ans++;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
