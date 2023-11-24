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
#define N 500005
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
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    sort(a+1, a+n+1);
    int l = 1, r = n;
    ll tot=0LL;
    ll sum=0LL;
    while(l < r) {
      if (sum + a[l] <= a[r]) {
        sum += a[l];
        tot += a[l];
        l++;
      } else {
        ll dt = a[r]-sum;
        tot += dt;
        a[l]-=dt;
        tot++;
        r--;
        sum = 0;
      }
     // cout<<l<<" "<<r<<" "<<sum<<" "<<tot<<endl;
    }
    if (sum > a[r]) {
      tot += a[r];
    } else {
      ll x = (a[r]-sum)/2;
      ll z = sum+x;
      tot += min((ll)a[r], x + 1 + (a[r] - x - z));
    }
    printf("%lld\n", tot);
  }
  return 0;
}
