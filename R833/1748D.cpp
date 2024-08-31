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
#define M 505
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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int a,b,d;
    scanf("%d%d%d", &a, &b, &d);
    int k = 0;
    while((d%2)==0) {
      k++;
      d/=2;
    }
    ll res=a|b;
    int i;
    for (i = 0; i < k; ++i) {
      if ((1<<i) & res) {
        break;
      }
    }
    if (i < k) {
      puts("-1");
      continue;
    }
    ll x = (d+1)/2;
    res = 1LL;
    for (int i = 0; i < 30 - k; ++i) {
      res = res * x % d;
    }
    res = (res + d - 1) % d;
    res = (((res + 1)<<(30-k))-1)<<k;
    printf("%lld\n", res);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
 
