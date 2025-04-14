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
#define M 10000005
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
bool check(int i, ll x, ll y, int c1, int c2) {
    int b1 = ((1LL<<i)&x)>0;
    int b2 = ((1LL<<i)&y)>0;
    if (c1) b1 ^=1;
    if (c2) b2 ^= 1;
    return b1 == b2;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll x,y;
    scanf("%lld%lld", &x, &y);
    int c1=0,c2=0;
    ll ans=0LL;
    for (int i = 0; i <= 31; ++i) {
        int b1 = ((1LL<<i)&x)>0;
        int b2 = ((1LL<<i)&y)>0;
        if (c1) {
            if (!b1) c1=0;
            b1 ^= 1;
        }
        if (c2) {
            if (!b2) c2=0;
            b2 ^= 1;
        }
      // if (i<=6) cout<<"i="<<i<<" "<<b1<<" "<<b2<<" "<<c1<<" "<<c2<<endl;
        if (b1 != b2) {
            if (check(i+1, x, y, c1 ,c2)) {
                ans ^= (1LL<<i);
                if (b1) c1 = 1;
                if (b2) c2 = 1;
            }
        } else {
            if (b1 && b2) {
                ans ^= (1LL<<i);
                c1 = 1;
                c2 = 1;
            }
        }
       // if (i<=6) cout<<"i2="<<i<<" "<<b1<<" "<<b2<<" "<<c1<<" "<<c2<<" "<<ans<<endl;
    }
    if (c1 && c2) {
        puts("-1");
    } else {
        printf("%lld\n", ans);
    }
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
