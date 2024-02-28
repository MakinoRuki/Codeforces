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
int a[N];
ll x,b;
ll solve(int k) {
    ll tot=-(ll)(k-1)*(ll)x;
    for (int i = 1; i <= n; ++i) {
        if (k >= a[i]) {
            tot += (ll)a[i]*(ll)(a[i]-1)/2LL*b;
        } else {
            int q = a[i]/k;
            int r = a[i]%k;
            ll tmp=(ll)r*(ll)(q+1)*(ll)(a[i]-(q+1));
            tmp += (ll)(k-r)*(ll)q*(ll)(a[i]-q);
            tmp/=2LL;
            tot += tmp * b;
        }
    }
    return tot;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int tot=0;
    scanf("%d%lld%lld", &n, &b, &x);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        tot += a[i];
    }
    int l = 1, r = tot;
    while(l < r) {
        int lmid = l + (r-l)/3;
        int rmid = r - (r-l)/3;
        //cout<<"lr="<<l<<" "<<r<<" "<<lmid<<" "<<rmid<<endl;
        ll res1=solve(lmid);
        ll res2=solve(rmid);
      //  cout<<"lr="<<l<<" "<<r<<" "<<lmid<<" "<<rmid<<" "<<res1<<" "<<res2<<endl;
        if (res1 >= res2) {
            r = rmid-1;
        } else {
            l = lmid+1;
        }
    }
    ll res=-1;
   // cout<<"x="<<solve(l)<<" "<<solve(r)<<endl;
    if (l >= 1 && l <= tot) res=(res<0?solve(l):max(res,solve(l)));
    if (r >= 1 && r <= tot) res=(res<0?solve(r):max(res,solve(r)));
    printf("%lld\n", res);
  }
  return 0;
}

