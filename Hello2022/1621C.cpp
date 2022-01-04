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
#define N 10005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
int a[N];
int b[N];
bool vis[N];
int ans[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      vis[i] = false;
    }
    for (int i = 1; i <= n; ++i) {
      if (!vis[i]) {
        vector<int> res;
        res.clear();
        int cur=i;
        while(true) {
          printf("? %d\n", i);
          fflush(stdout);
          int x;
          scanf("%d", &x);
          if (vis[x]) {
            break;
          }
          res.push_back(x);
          vis[x] = true;
        }
        int sz = (int)res.size();
        for (int j = 0; j < res.size(); ++j) {
          ans[res[j]] = res[(j+1)%sz];
        }
      }
    }
    printf("!");
    for (int i = 1; i <= n; ++i) {
      printf(" %d", ans[i]);
    }
    cout<<endl;
    fflush(stdout);
  }
  return 0;
}
