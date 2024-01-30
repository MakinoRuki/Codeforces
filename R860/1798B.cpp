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
#define N 300005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N], b[N];
int ans[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &m);
    vector<vector<int>> v;
    v.clear();
    for (int i = 1; i <= m; ++i) {
      scanf("%d", &n);
      ans[i]=-1;
      vector<int> tmp;
      tmp.clear();
      for (int j = 1; j <= n; ++j) {
        int x;
        scanf("%d", &x);
        tmp.push_back(x);
      }
      v.push_back(tmp);
    }
    bool ok=true;
    set<int> ss;
    ss.clear();
    for (int i = m; i >= 1; --i) {
      for (int j = 0; j < v[i-1].size(); ++j) {
        int x=v[i-1][j];
        if (ss.find(x) == ss.end()) {
          ans[i] = x;
          break;
        }
      }
      if (ans[i] < 0) {
        ok=false;
        break;
      }
      for (int j = 0; j < v[i-1].size(); ++j) {
        ss.insert(v[i-1][j]);
      }
    }
    if (!ok) puts("-1");
    else {
      for (int i = 1; i <= m; ++i) {
        printf("%d ", ans[i]);
      }
      cout<<endl;
    }
  }
  return 0;
}
