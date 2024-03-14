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
#define N 300005
#define M 2005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
ll a[M];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
      scanf("%d%d", &n, &m);
      vector<pair<int,int>> v;
      v.clear();
      for (int i =1 ; i <= n; ++i) {
          int x,y;
          scanf("%d%d", &x, &y);
          v.push_back(make_pair(y, x));
      }
      sort(v.begin(), v.end());
      int ans=0;
      for (int i = 1; i <= n; ++i) {
          set<pair<int,int>> ss;
          ss.clear();
          ll tot=0LL;
          for (int j = i; j <= n; ++j) {
              ss.insert(make_pair(v[j-1].second, j));
              tot += v[j-1].second;
              while (!ss.empty() && tot + v[j-1].first - v[i-1].first > m) {
                  tot -= (*ss.rbegin()).first;
                  ss.erase(--ss.end());
              }
              ans = max(ans, (int)ss.size());
          }
      }
      printf("%d\n", ans);
  }
  return 0;
}
