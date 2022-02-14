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
#define M 202
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
ll a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
      // a[i] = rand()%20;
      // cout<<a[i]<<" ";
    }
  //  cout<<endl;
    int pmx = -1;
    ll tot=0LL;
    for (int i = 1; i <= n; ++i) {
      if ((i-1<1 || a[i]>=a[i-1]) && (i+1<=n && a[i] > a[i+1])) {
        pmx = a[i];
      } else if ((i-1>=1 && a[i]<a[i-1]) && (i+1>n || a[i]<=a[i+1])) {
        if (pmx >= 0) {
          tot += abs(pmx - a[i]);
        }
      }
    }
    printf("%lld\n", tot);
  }
  return 0;
}
