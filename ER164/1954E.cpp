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
#include <stack>
#include <bitset>
#define N 500005
#define M 325
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
int c[N];
ll sum[N];
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  memset(c, 0, sizeof(c));
  memset(sum, 0LL, sizeof(sum));
  int mx=0;
  for (int i = 1; i <= n; ++i) {
    mx = max(mx, a[i]);
    if (i == 1|| a[i] >= a[i-1]) {
      c[i]++;
    }
    if (i +1 <=n && a[i] <= a[i+1]) {
      c[i]--;
    }
    sum[a[i]] += c[i];
  }
  for (int i = 1; i <= mx; ++i) {
    sum[i] += sum[i-1];
  }
  for (int k = 1; k <= mx; ++k) {
    ll ans = 0LL;
    for (int i = 1; i <= mx; i += k) {
      int r = min(i+k-1, mx);
      ll dt = sum[r] - sum[i-1];
    //  if (k==1) cout<<"i="<<i<<" "<<r<<" "<<dt<<endl;
      dt = dt * (ll)(i + k-1)/(ll)k;
      ans += dt;
    }
    printf("%lld ", ans);
  }
  cout<<endl;
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

