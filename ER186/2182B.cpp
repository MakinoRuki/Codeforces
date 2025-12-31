
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
#define M 8002
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
ll a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x,y;
    scanf("%d%d", &x, &y);
    ll nx=0,ny=0;
    ll ans=0LL;
    ll res=0LL;
    for (int i = 1; i <= 50; ++i) {
      if (i&1) {
        if (nx + (1LL<<(i-1)) <= x) {
          nx += 1LL<<(i-1);
          res=i;
        } else {
          break;
        }
      } else {
        if (ny + (1LL<<(i-1)) <= y) {
          ny += 1LL<<(i-1);
          res=i;
        } else {
          break;
        }
      }
    }
    ans = max(ans, res);
    nx=0,ny=0;
    res=0;
    for (int i = 1; i <= 50; ++i) {
      if ((i%2)==0) {
        if (nx + (1LL<<(i-1)) <= x) {
          nx += 1LL<<(i-1);
          res=i;
        } else {
          break;
        }
      } else {
        if (ny + (1LL<<(i-1)) <= y) {
          ny += 1LL<<(i-1);
          res=i;
        } else {
          break;
        }
      }
    }
    ans=max(ans, res);
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
