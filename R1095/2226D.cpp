
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
#define M 5002
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
 //  ll x, y;
   scanf("%d", &n);
   int mx0=-1,mn0=inf;
   int mx1=-1,mn1=inf;
   for (int i = 1; i <= n; ++i) {
     scanf("%d", &a[i]);
     if (a[i]%2) {
       mx1=max(mx1, a[i]);
       mn1=min(mn1, a[i]);
     } else {
       mx0=max(mx0, a[i]);
       mn0=min(mn0, a[i]);
     }
   }
   int pre=-1;
   bool ok=true;
   for (int i = 1; i <= n; ++i) {
     if (a[i] % 2) {
       if (pre < 0) pre = a[i];
       else {
         if (a[i] < pre) {
           if (mx0<0 || (mx0<pre && mn0 > a[i])) {
             ok=false;
             break;
           }
         }
         pre = max(pre , a[i]);
       }
     }
   }
   pre = -1;
   for (int i = 1; i <= n; ++i) {
     if (!(a[i] % 2)) {
       if (pre < 0) pre = a[i];
       else {
         if (a[i] < pre) {
           if (mx1<0 || (mx1<pre && mn1 > a[i])) {
             ok=false;
             break;
           }
         }
         pre = max(pre , a[i]);
       }
     }
   }
   if (ok) puts("Yes");
   else puts("No");
 }
 return 0;
}
