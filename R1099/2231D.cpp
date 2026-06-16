
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
ll a[N];
ll c[N];
ll b[N];
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
   ll x, y;
   scanf("%d", &n);
   string s;
   cin>>s;
   for (int i = 1; i <= n; ++i) {
     scanf("%lld", &a[i]);
   }
   for (int i = 1; i <= n; ++i) {
     scanf("%lld", &c[i]);
   }
   bool ok=true;
   if (s[0] == '1' && a[1] != c[1]) {
     puts("No");
     continue;
   }
   b[1] = c[1];
   ll sum=b[1];
   int pre=-1;
   ll px=sum;
   for (int i = 2; i <= n; ++i) {
     if (c[i] == c[i-1]) {
       if (s[i-1] == '0') {
         pre=i; 
         // 要保证当前sum取道前缀最大值px。
         // 比如：
         // 4
         // 0101
         // 0 -3 0 5
         // 5 5 5 10
         b[i]=c[i]-sum;
         sum=c[i];
         px=c[i];
       } else {
         b[i]=a[i];
         sum += b[i];
         px=max(px, sum);
         if (px==c[i]) continue;
         if (px < c[i]) {
           ok=false;
           break;
         }
         if (pre<0) {
           ok=false;
           break;
         }
         ll dt = sum-c[i];
         b[pre] -= dt;
         sum = c[i];
         px=sum;
         // 这里不能把pre清掉，因为pre这个位置还可以继续把后面的数字变小。
         // 比如：
         // 4
         // 1011
         // 10 0 5 5
         // 10 10 10 10
         // pre=-1;
       }
     } else if (c[i] > c[i-1]) {
       if (s[i-1] == '0') {
         b[i] = c[i]-sum;
         sum = c[i];
         px=sum;
         pre = -1;
       } else {
         b[i] = a[i];
         sum += b[i];
         px=max(px, sum);
         if (px == c[i]) continue;
         if (px < c[i]) {
          ok=false;
          break;
         }
         if (pre < 0) {
           ok=false;
           break;
         }
         ll dt = sum-c[i];
         b[pre] -= dt;
         sum = c[i];
         px=sum;
         pre= -1;
       }
     } else {
       ok=false;
       break;
     }
   }
   ll mx=b[1];
   a[1]=b[1];
   for (int i = 2; i <= n; ++i) {
     a[i]=b[i];
     b[i] += b[i-1];
     mx =max(mx, b[i]);
     if (mx != c[i]) {
       ok=false;
       break;
     }
   }
   if (!ok) puts("No");
   else {
     puts("Yes");
     for (int i = 1; i <= n; ++i) {
       printf("%lld ", a[i]);
     }
     cout<<endl;
   }
 }
 return 0;
}


