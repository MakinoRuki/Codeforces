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
#define N 200005
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    if (n == 1) {
      puts("YES");
    } else {
      if (a[1] == a[n]) {
        int cnt=0;
        for (int i= 1; i <= n; ++i) {
          if (a[i] == a[1]) cnt++;
        }
        if (cnt >= k) {
          puts("YES");
        } else {
          puts("NO");
        }
      } else {
        int i,j;
        int cnt=0;
        for (i = 1; i <= n; ++i) {
          if (a[i] == a[1]) {
            cnt++;
            if (cnt >= k) break;
          }
        }
        cnt=0;
        for (j = n; j >= 1; --j) {
          if (a[j] == a[n]) {
            cnt++;
            if (cnt >= k) break;
          }
        }
        if (i < j) {
          puts("YES");
        } else {
          puts("NO");
        }
      }
    }
  }
  return 0;
}
