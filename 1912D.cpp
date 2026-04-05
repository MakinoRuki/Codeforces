/*
可以发现，这三种情况分别等价于(b^k)%n=0/1/-1。枚举k，然后找最小的k满足三者之一。注意这个k的上界可能很大。可以枚举到n。
*/

#include <iostream>
#include <sstream>
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
#define N 2000005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 1000003;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
int p[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  // ll ans=1LL;
  // for (int i =1; i <= 500; ++i) {
  //   ans=ans*5813LL%9422LL;
  // }
  // cout<<ans<<endl;
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll b,m;
    scanf("%lld%lld", &b, &m);
    int res=m+1;
    ll cur=b;
    int id=-1;
    for (int i = 1; i <= m; ++i) {
      if ((cur % m)==0) {
        id = 1;
        res=min(res, i);
        break;
      }
      if ((cur%m) == 1) {
        id=2;
        res=min(res,i);
        break;
      }
      if (((cur%m) + 1)%m == 0) {
        id = 3;
        res=min(res,i);
        break;
      }
      cur=cur*(b%m)%m;
    //  if (i == 500)
    }
    if (id < 0) {
      puts("0");
    } else {
      printf("%d %d\n", id, res);
    }
  }
  return 0;
}

