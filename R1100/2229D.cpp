
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
int b[N];
ll lsum[N], rsum[N];
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
   ll x;
   scanf("%d", &n);
   for (int i = 1; i <= n; ++i) {
     scanf("%d", &a[i]);
   }
   for (int i = 1; i <= n; ++i) {
     scanf("%d", &b[i]);
   }
   int l = 1, r = 2*n;
   while(l < r) {
     int mid = (l+r+1)/2;
   //  cout<<"mid="<<mid<<endl;
     int c1=0,c0=0;
     int n00=0,n01=0,n11=0;
     int dt = 0;
     int n0=0,n1=0,n2=0;
     for (int i = 1; i <= n; ++i) {
       int x = (a[i]>=mid);
       int y = (b[i]>=mid);
       if (x && y) {
         dt += 2;
         n2++;
         if (n00>0) {
           dt += 2*(n00-1);
           n0++;
         } else if (n01>0) {
           n1++;
         }
         n00=0,n01=0;
       } else if (!x && !y) {
         n00++;
         dt -= 2;
       } else {
         n01++;
       }
     //  if (mid==4) cout<<"i="<<i<<" "<<dt<<endl;
     }
   //  if (mid==4) cout<<"dt="<<dt<<endl;
     if (n00>0) {
       dt += 2*(n00-1);
       n0++;
     } else if (n01>0) {
       n1++;
     }
     n2 -= 2*n0+n1;
     if (n2 > 1) dt -= 2*(n2-1);
  //   if (mid == 4) cout<<"dt="<<dt<<" "<<n2<<endl;
     if (dt > 0) {
       l = mid;
     } else {
       r = mid-1;
     }
   }
   printf("%d\n", r);
 }
 return 0;
}


