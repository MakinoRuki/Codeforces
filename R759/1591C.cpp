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
#define N 200005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k;
int t;
string s;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    int x = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    sort(a+1, a+n+1);
    ll tot=0LL;
    int cnt=0;
    for (int i = n; i >= 1; --i) {
      if (a[i] <= 0) {
        break;
      }
      if (cnt % k == 0) {
        tot += 2LL*a[i];
      }
      cnt++;
    }
    cnt=0;
    for (int i =1; i <= n; ++i) {
      if (a[i] >= 0) {
        break;
      }
      if (cnt%k == 0) {
        tot += 2LL*abs(a[i]);
      }
      cnt++;
    }
 //   cout<<"tot="<<tot<<endl;
    if (a[1] >= 0) {
      tot -= a[n];
    } else if (a[n] <= 0) {
      tot -= abs(a[1]);
    } else {
      tot -= max(a[n], abs(a[1]));
    }
    printf("%lld\n", tot);
  }
  return 0;
}
