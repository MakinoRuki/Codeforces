
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
ll sum[3*N];
int main() {
 cin>>t;
 for (int cas=1; cas<=t; ++cas) {
 //  ll x, y;
   scanf("%d%d", &n, &k);
 //  string s;
   for (int i = 1; i <= n; ++i) {
     scanf("%d", &a[i]);
   }
   sum[0]=0;
   for (int i = 1; i <= 3*n; ++i) {
     sum[i] = sum[i-1];
     if (i <= n) sum[i] += a[i];
     else if (i <= 2*n) sum[i] += a[i-n];
     else sum[i] += a[i-2*n];
   }
   ll ans=0LL;
   for (int i = 1; i <= n; ++i) {
     int id = i+n;
     // 放入i的时候如果某个j已经放入了，也会产生+a[i]。
     // 因为之前j在放入的时候提前减掉了a[j]，这时候要把这部分补回来。
     ll dt = 2LL*k*a[i] - (sum[id+k]-sum[id-k-1]-a[i]);
     if (dt >= 0) ans += dt;
   }
   printf("%lld\n", ans);
 }
 return 0;
}
