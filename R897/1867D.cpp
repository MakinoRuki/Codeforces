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
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
bool vis[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      vis[i] = false;
    }
    bool ok=true;
    if (k == 1) {
      for (int i = 1; i <= n; ++i) {
        if (a[i] != i) {
          ok=false;
          break;
        }
      }
    } else {
      for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
          set<int> ss;
          ss.clear();
          int cur=i;
          while(true) {
            if (vis[cur]) break;
            if (ss.find(cur) != ss.end()) {
              break;
            }
            ss.insert(cur);
            cur = a[cur];
          }
          if (!vis[cur]) {
            int len=0;
            int j = cur;
            while(true) {
              len++;
              j = a[j];
              if (j == cur) break;
            }
            if (len != k) {
              ok=false;
              break;
            }
          }
          while(!ss.empty()) {
            vis[*ss.begin()] = true;
            ss.erase(ss.begin());
          }
        }
      }
    }
    if (ok) puts("YES");
    else puts("NO");
  }
  return 0;
}
