
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
int c[N];
int main() {
 cin>>t;
 for (int cas=1; cas<=t; ++cas) {
 //  ll x, y;
   scanf("%d%d", &n, &k);
 //  string s;
   int ans=0;
   for (int i = 0; i <= 30; ++i) {
    if (n <= 0) break;
     if (n / (1LL<<i) >= k) {
       ans += k;
       n -= (1LL<<i) * k;
     } else {
       int dt = n/(1LL<<i);
       ans += dt;
       n -= dt * (1LL<<i);
     }
   } 
   printf("%d\n", ans);
 }
 return 0;
}
