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
#define N 1000005
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
    set<int> ss;
    ss.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      ss.insert(a[i]);
    }
    int l = 1, r = n;
    while(l < r) {
      int mn = (*ss.begin());
      int mx = (*ss.rbegin());
      if (a[l] == mn || a[l] == mx) {
        ss.erase(a[l]);
        l++;
      } else if (a[r] == mn || a[r] == mx) {
        ss.erase(a[r]);
        r--;
      } else {
        break;
      }
    }
    if (l < r) {
      printf("%d %d\n", l, r);
    } else {
      puts("-1");
    }
  }
  return 0;
}
