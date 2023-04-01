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
#define N 3005
#define M 22
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
ll pw[N];
int main() {
  cin>>n;
  pw[0] = 1LL;
  for (int i = 1; i <= n; ++i) {
    pw[i] = pw[i-1] * (ll)2LL % mod;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  a[0] = 0;
  a[n+1] = 1000000010;
  ll ans = 0LL;
  for (int i = 1; i <= n; ++i) {
    for (int j = i+1; j <= n; ++j) {
      ll tmp=1LL;
      int d = a[j]-a[i];
      int l = j+1, r = n+1;
      while(l < r) {
        int mid=(l+r)/2;
        if (a[mid]-a[j]<d) {
          l=mid+1;
        } else {
          r = mid;
        }
      }
      tmp = tmp * pw[n+1-r] % mod;
      l = 0, r = i-1;
      while(l < r) {
        int mid = (l+r+1)/2;
        if (a[i]-a[mid] <= d) {
          r = mid-1;
        } else {
          l = mid;
        }
      }
      tmp = tmp * pw[r] % mod;
      ans = (ans + tmp) % mod;
    }
  }
  cout<<ans<<endl;
  return 0;
}
