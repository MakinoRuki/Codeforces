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
#define N 2000
#define M 2505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int ans[N];
void check(int bt, int v) {
  vector<int> ids;
  ids.clear();
  for (int j = 1; j <= n; ++j) {
    int x = ((1<<bt)&j)>0;
    if (x == v) {
      ids.push_back(j);
    }
  }
  if (ids.size() > 0) {
    printf("%d\n", (int)ids.size());
    fflush(stdout);
    for (int j = 0; j < ids.size(); ++j) {
      printf("%d ", ids[j]);
    }
    cout<<endl;
    fflush(stdout);
    for (int j = 1; j <= n; ++j) {
      int x = ((1<<bt)&j)>0;
      int res;
      scanf("%d", &res);
      if (x != v) {
        ans[j] = (ans[j] < 0 ? res: min(ans[j], res));
      }
    }
  }
}
int main() {
  // cin>>t;
  // mt19937 rnd(time(0));
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d", &n);
    
  // }
  memset(ans, -1, sizeof(ans));
  scanf("%d", &n);
  for (int i = 0; i < 10; ++i) {
    check(i, 0);
    check(i, 1);
  }
  puts("-1");
  for (int i = 1; i <= n; ++i) {
    printf("%d", ans[i]);
    if (i < n) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
