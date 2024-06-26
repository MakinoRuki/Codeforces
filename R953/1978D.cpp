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
#define N 500005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
int mx[N];
int ans[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    //ll k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    int cur = 0;
    for (int i = n; i >= 1; --i) {
      mx[i] = cur;
      cur = max(cur, a[i]);
    }
    cur = 0;
    ll tot=0LL;
    for (int i = 1; i <= n; ++i) {
      int tmp = a[i];
      if (i == 1) tmp += k;
      if (cur >= tmp || mx[i] > tmp) {
        if (tmp + tot >= mx[i]) {
          ans[i] = i-1;
        } else {
          ans[i] = i;
        }
      } else {
        ans[i] = 0;
      }
      cur = max(cur, tmp);
      tot += tmp;
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d ", ans[i]);
    }
    cout<<endl;
  }
  return 0;
}
