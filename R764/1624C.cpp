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
#define N 52
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, q, k;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    set<int> ss;
    ss.clear();
    for (int i = 1; i <= n; ++i) {
      ss.insert(i);
    }
    for (int i = 1; i <= n; ++i) {
      int x = a[i];
      while(x) {
        if (ss.find(x) != ss.end()) {
          ss.erase(x);
          break;
        }
        x /= 2;
      }
    }
    if (ss.empty()) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}
