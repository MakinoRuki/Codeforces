
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
   scanf("%d%d", &n, &k);
 //  string s;
   vector<pair<int,int>> rk;
   rk.clear();
   for (int i = 1; i <= n; ++i) {
     scanf("%d", &a[i]);
     rk.push_back(make_pair(a[i], i));
   }
   sort(rk.begin(), rk.end());
   vector<pair<int,int>> rk2;
   rk2.clear();
   for (int i = 1; i <= n; ++i) {
     scanf("%d", &b[i]);
     rk2.push_back(make_pair(b[i], i));
   }
   sort(rk2.begin(), rk2.end());
   int ans = 0;
   bool ok=true;
   for (int i = 0; i < n; ++i) {
     if (rk[i].first < rk2[i].first) {
       ans=-1;
       break;
     }
     ans += abs(rk[i].first-rk2[i].first);
     if (rk[i].second != rk2[i].second) {
       ok=false;
     }
   }
   if (ans<0) {
     puts("-1");
     continue;
   }
   if (!ok) ans += k;
   int sum=0;
   for (int i = 1; i <= n; ++i) {
     if (a[i] < b[i]) {
       sum=-1;
       break;
     }
     sum += a[i]-b[i];
   }
   if (sum >=0) ans = min(ans, sum);
   printf("%d\n", ans);
 }
 return 0;
}
