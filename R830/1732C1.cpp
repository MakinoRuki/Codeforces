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
#define N 1000005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
ll sum[N];
ll xsum[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &q);
    sum[0]=0LL;
    xsum[0]=0LL;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        sum[i] = sum[i-1] + a[i];
        xsum[i] = xsum[i-1] ^ a[i];
    }
    ll mx = -1;
    int l,r;
    int x,y;
    scanf("%d%d", &x, &y);
    for (int i = 1; i <= n; ++i) {
        mx = max(mx, sum[i]-xsum[i]);
    }
    int i=0;
    int len=n+1;
    for (int j = 1; j <= n; ++j) {
        while(i < j && (sum[j]-sum[i]-(xsum[j]^xsum[i]))==mx) {
            if (j-i<len) {
                len=j-i;
                l=i+1;
                r=j;
            }
            i++;
        }
       // cout<<j<<" "<<i<<" "<<sum[j]<<" "<<sum[i]<<" "<<xsum[j]<<" "<<xsum[i]<<" "<<mx<<endl;
    }
    printf("%d %d\n", l, r);
  }
  return 0;
}
