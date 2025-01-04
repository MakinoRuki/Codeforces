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
#define N 300005
#define M 2010
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
ll getgcd(ll x, ll y) {
    return y == 0 ? x : getgcd(y, x%y);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
      ll l, r, g;
      scanf("%lld%lld%lld", &l, &r, &g);
      ll r2 = r/g;
      ll l2 = (l-1)/g+1;
      ll x=-1,y=-1;
      if (l2 <= r2) {
          for (ll i = l2; i <= min(l2+30,r2); ++i) {
              for (ll j = r2; j >= max(r2-30,l2); --j) {
                  if (i<=j) {
                      ll g1 = getgcd(i, j);
                      if (g1 == 1) {
                          if (x<0) {
                              x=i,y=j;
                          } else if (j-i+1>y-x+1) {
                              x=i,y=j;
                          } else if ((j-i+1==y-x+1) && i < x) {
                              x=i,y=j;
                          }
                      }
                  }
              }
          }
      }
      if (x >= 0) {
          x*=g;
          y*=g;
      }
      printf("%lld %lld\n", x, y);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
