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
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    set<int> ss;
    ss.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      ss.insert(abs(a[i]));
    }
    if (n == 1) {
      if (a[1] == 0) {
        puts("YES");
      } else {
        puts("NO");
      }
    } else {
      int sz = (int)ss.size();
      if (sz < n || ss.find(0) != ss.end()) {
        puts("YES");
      } else {
        bool ok=false;
        int pw = 1;
        for (int i = 1; i <= n; ++i) {
          pw *= 3;
        }
        for (int i = 1; i <= n; ++i) {
          for (int j = 0; j < pw; ++j) {
            int sum = 0;
            int id = -1;
            int x = j;
            for (int j2 = 0; j2 < n; ++j2) {
              if (x%3 != 0) {
                if (j2 +1 == i) id = j2+1;
                if (x % 3 == 1) {
                  sum += abs(a[j2+1]);
                } else {
                  sum -= abs(a[j2+1]);
                }
              }
              x /= 3;
            }
            if (id == i) continue;
            if (sum == a[i]) {
              ok=true;
              break;
            }
          }
          if (ok) break;
        }
        if (ok) puts("YES");
        else puts("NO");
      }
    }
  }
  return 0;
}
