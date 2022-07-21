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
#define N 200005
#define M 300005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int a[N];
vector<int> ids[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      ids[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      ids[a[i]].push_back(i);
    }
    for (int i =1; i <= n; ++i) {
      int cnt=0;
      int ans=0;
      int p = 0;
      for (int j = 0; j < ids[i].size(); ++j) {
        if ((ids[i][j]%2) == p) {
          cnt++;
          p = !p;
        }
      }
      ans=max(ans, cnt);
      cnt=0;
      p = 1;
      for (int j = 0; j < ids[i].size(); ++j) {
        if ((ids[i][j]%2) == p) {
          cnt++;
          p = !p;
        }
      }
      ans = max(ans, cnt);
      printf("%d", ans);
      if (i < n) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
