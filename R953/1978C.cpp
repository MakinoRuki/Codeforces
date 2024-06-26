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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll k;
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; ++i) {
      a[i] = i;
    }
    if (k%2) {
      puts("No");
      continue;
    }
    int l = 1, r = n;
    ll tot=0LL;
    while(l < r) {
      tot += 2LL*abs(r-l);
      l++;
      r--;
    }
    if (k >= 0 && k <= tot) {
      l = 1, r = n;
      while(k) {
        ll dt = 2LL*abs(l-r);
        if (k >= dt) {
          swap(a[l], a[r]);
          l++,r--;
          k -= dt;
        } else {
          swap(a[l], a[l+k/2]);
          break;
        }
      }
      puts("Yes");
      for (int i = 1; i <= n; ++i) {
        printf("%d ", a[i]);
      }
      cout<<endl;
    } else {
      puts("No");
    }
  }
  return 0;
}
