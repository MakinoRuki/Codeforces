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
#define N 600005
#define M 750
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int res[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll l,r;
    scanf("%d%lld%lld", &n, &r, &r);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    res[0]=0;
    for (int i = 1; i <= n; ++i) {
        res[i] = res[i-1] ^ a[i];
    }
    if ((n%2)==0) {
        n++;
        a[n]=0;
        for (int i = 1; i <= n/2; ++i) {
            a[n] ^= a[i];
        }
        res[n] = res[n-1] ^ a[n];
    }
    if (r <= n) {
        printf("%d\n", a[r]);
        continue;
    }
    ll ans=0LL;
    while(r > n) {
        ll r2=r/2;
        if (r2 <= n) {
            ans ^= res[r2];
        } else {
            ans ^= res[n];
            if (r2%2) {
                break;
            }
        }
        r = r2;
    }
    printf("%lld\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
