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
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,n,d;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    sort(a+1, a+n+1);
    for (int i = n; i >= 3; --i) {
      if (a[1]+a[2] <= a[i]) a[i] = a[1]+a[2];
    }
    int i;
    for (i = 1; i <= n; ++i) {
      if (a[i] > d) {
        break;
      }
    }
    if (i <= n) {
      cout<<"NO"<<endl;
    } else {
      cout<<"YES"<<endl;
    }
  }
  return 0;
}
