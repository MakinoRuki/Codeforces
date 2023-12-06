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
#define N 200000
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    vector<pair<int,int>> ans;
    ans.clear();
    vector<int> ids;
    ids.clear();
    for (int i = 1; i <= n; ++i) {
      if ((a[i]%2) == (a[1]%2)) {
        ids.push_back(i);
      }
    }
    for (int i = ids.size()-2; i >= 0; --i) {
      ans.push_back(make_pair(ids[i], ids[i+1]));
    }
    for (int i = 2; i <= n; ++i) {
      if ((a[i]%2) != (a[1]%2)) {
        ans.push_back(make_pair(1, i));
      }
    }
    int sz = (int)ans.size();
    printf("%d\n", sz);
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d %d\n", ans[i].first, ans[i].second);
    }
  }
  return 0;
}
