
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
   int tot=0;
   for (int i = 1; i <= n; ++i) {
     scanf("%d", &a[i]);
   }
   if (n <= 1) {
     puts("0");
     continue;
   }
   for (int i = 1; i <= n; ++i) {
     tot ^= a[i];
   }
   int ans=0;
   if (tot == 0) {
     ans=1;
   } else {
     for (int i = 1; i <= n; ++i) {
      if ((a[i] ^ tot)<=a[i]) {
        ans++;
      }
    }
   }
   
   printf("%d\n", ans);
 }
 return 0;
}
