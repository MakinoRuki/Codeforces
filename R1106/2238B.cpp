
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
#define M 1805
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 676767677;
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
int b[N];
int main() {
 cin>>t;
 for (int cas=1; cas<=t; ++cas) {
 //  ll x, y;
   scanf("%d", &n);
 //  string s;
   ll ans=0LL;
   for (int i= 1; i <= n; ++i) {
     ll dt = n/i;
     // gcd(lcm(a,b),lcm(b,c))=gcd(a,c)
     // 看每个素因子p的指数，P(a)=x,P(b)=y,P(c)=z.
     // 左边永远大于等于右边。只有y>m时，左边才会大于右边。
     // 所以要想等于那么y<=m也就是b|gcd(a,c)。
     ans += dt*dt;
   }
   printf("%lld\n", ans);
 }
 return 0;
}
