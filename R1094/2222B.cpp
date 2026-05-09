
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
#define N 1000005
#define M 15
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
   scanf("%d%d", &n, &m);
   vector<int> v0,v1;
   v0.clear();
   v1.clear();
   ll tot=0LL;
   for (int i = 1; i <= n; ++i) {
     scanf("%d", &a[i]);
     if (i%2) v1.push_back(a[i]);
     else v0.push_back(a[i]);
     tot += a[i];
   }
   sort(v1.begin(), v1.end());
   sort(v0.begin(), v0.end());
   int n0=0,n1=0;
   for (int i = 1; i <= m; ++i) {
     scanf("%d", &b[i]);
     if (b[i] %2) n1++;
     else n0++;
   }
   reverse(v0.begin(), v0.end());
   reverse(v1.begin(), v1.end());
   if (n0) {
     if (!v0.empty()) {
       if (v0[0]<0) tot -= v0[0];
       else {
         for (int i = 0; i < min(n0, (int)v0.size()); ++i) {
           if (v0[i] < 0) break;
           tot -= v0[i];
         }
       }
     }
   }
   if (n1) {
     if (!v1.empty()) {
       if (v1[0]<0) tot -= v1[0];
       else {
         for (int i = 0; i < min(n1, (int)v1.size()); ++i) {
           if (v1[i] < 0) break;
           tot -= v1[i];
         }
       }
     }
   }
   printf("%lld\n", tot);
 }
 return 0;
}


