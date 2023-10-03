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
#define N 200010
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
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      ans = max(ans, a[i]);
    }
    int l = ans, r = 1000000000;
    while(l < r) {
      int mid = (l + r + 1) / 2;
      bool ok = false;
      for (int i = 1; i < n; ++i) {
        ll tot=0;
        ll dt = mid - a[i];
        tot += dt;
        ll cur = mid - 1;
        for (int j = i+1; j < n; ++j) {
          if (cur > a[j]) {
            tot += cur - a[j];
            cur--;
          } else {
            cur = a[n];
            break;
          }
        }
        if (cur > a[n] || tot > k) {
          continue;
        }
        ok=true;
        // if (mid == 180) {
        //   cout<<"i="<<i<<endl;
        // }
        break;
      }
      if (ok) {
        l = mid;
      } else {
        r = mid-1;
      }
    }
    printf("%d\n", r);
  }
  return 0;
}
