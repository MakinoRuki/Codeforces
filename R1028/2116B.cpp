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
#include <chrono>
#define N 500005
#define M 1002
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m;
int k;
ll x;
int t;
int p[N];
int q[N];
//int a[N];
ll getpw(ll x, ll y) {
    ll res=1LL;
    while(y) {
        if (y&1) res=res*x%mod2;
        x=x*x%mod2;
        y/=2;
    }
    return res;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &q[i]);
    }
    int id0=0,id1=0;
    for (int i = 0; i < n; ++i) {
        if (p[i] > p[id0]) {
            id0 = i;
        }
        if (q[i] > q[id1]) {
            id1 = i;
        }
        if (p[id0] > q[id1]) {
            printf("%lld ", (getpw(2LL, p[id0]) + getpw(2LL, q[i-id0]))%mod2);
        } else if (p[id0] < q[id1]) {
            printf("%lld ", (getpw(2LL, p[i-id1]) + getpw(2LL, q[id1]))%mod2);
        } else {
            if (id0 + id1 == i) {
                printf("%lld ", (getpw(2LL, p[id0]) + getpw(2LL, q[id1]))%mod2);
            } else {
                if (q[i-id0] > p[i-id1]) {
                    printf("%lld ", (getpw(2LL, p[id0]) + getpw(2LL, q[i-id0]))%mod2);
                } else {
                    printf("%lld ", (getpw(2LL, p[i-id1]) + getpw(2LL, q[id1]))%mod2);
                }
            }
        }
    }
    cout<<endl;
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
