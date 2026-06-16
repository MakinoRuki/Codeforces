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
int ln,rn;
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
   scanf("%d", &n);
   int n0=0,n1=0;
   int mx0=-1,mn0=-1;
   int mx1=-1,mn1=-1;
   for (int i = 1; i <= n; ++i) {
     scanf("%d", &a[i]);
     if (a[i]%2) {
       n1++;
       if (mx1<0) {
         mx1=a[i];
         mn1=a[i];
       } else {
         mx1=max(mx1, a[i]);
         mn1=min(mn1, a[i]);
       }
     } else {
       n0++;
       if (mx0<0) {
         mx0=a[i];
         mn0=a[i];
       } else {
         mx0=max(mx0, a[i]);
         mn0=min(mn0, a[i]);
       }
     }
   }
   bool found=false;
   for (int i = 2; i <= n; ++i) {
     if (a[i] < a[i-1]) found=true;
   }
   if (!found) {
     puts("Yes");
     continue;
   }
   if (!n0 || !n1) {
     puts("No");
     continue;
   }
   bool ok=true;
   int id0=-1,id1=-1;
   for (int i = 1; i <= n; ++i) {
     if (a[i]%2 && a[i]>mx0) {
       id1=i;
       break;
     }
   }
   for (int i = n; i >= 1; --i) {
     if (a[i]%2 && a[i] < mn0) {
       id0 = i;
       break;
     }
   }
   if (id1 > 0 && id0 > 0 && id1< id0) {
     ok=false;
   }
   id0=-1,id1=-1;
   for (int i = 1; i <= n; ++i) {
     if (!(a[i]%2) && a[i]>mx1) {
       id1=i;
       break;
     }
   }
   for (int i = n; i >= 1; --i) {
     if (!(a[i]%2) && a[i] < mn1) {
       id0 = i;
       break;
     }
   }
   if (id1 > 0 && id0 > 0 && id1< id0) {
     ok=false;
   }
   if (ok) puts("Yes");
   else puts("No");
 }
 return 0;
}
