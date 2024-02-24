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
#define N 300005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N], b[N];
int ans[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    ll tot=0LL;
    for (int i =1 ; i <= n; ++i) {
        scanf("%d", &a[i]);
        
        if (i >= 2) {
            ll l = 1, r = a[i];
            while(l < r) {
                ll mid=(l+r)/2;
                ll dt = a[i]/mid+((a[i]%mid)>0);
                if (dt < 2LL*a[1]) {
                    r = mid;
                } else {
                    l = mid+1;
                }
            }
            tot += r-1;
        }
       // cout<<"i="<<i<<endl;
    }
    printf("%lld\n", tot);
  }
  return 0;
}
