
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
   lsum[0]=0;
   for (int i = 1; i <= n; ++i) {
     lsum[i] = lsum[i-1] + abs(a[i]);
   }
   rsum[n+1]=0;
   for (int i = n; i >= 1; --i) {
     rsum[i] = rsum[i+1] + a[i];
   }
   ll ans = rsum[1];
   int id=0;
   for (int i = 1; i <= n; ++i) {
     if (a[i]>0 && lsum[i-1]-abs(a[i])+rsum[i+1] > ans) {
       ans = lsum[i-1]-abs(a[i])+rsum[i+1];
       id = i;
      // cout<<"id="<<id<<" "<<ans<<endl;
     }
   }
   if (id == 0) {
     puts("0");
     continue;
   }
   int cur=0;
   vector<int> v;
   v.clear();
   if (id == 1 || a[id-1] < 0) {
     for (int i = id-1; i >= 1; --i) {
       if (a[i] > 0 && !cur) {
         v.push_back(i);
         cur = !cur;
       } else if (a[i] < 0 && cur) {
         v.push_back(i);
         cur= !cur;
       }
     }
     v.push_back(id);
   } else {
     v.push_back(id-1);
     cur = 1;
     for (int i = id-1; i >= 1; --i) {
       if (a[i] > 0 && !cur) {
         v.push_back(i);
         cur = !cur;
       } else if (a[i] < 0 && cur) {
         v.push_back(i);
         cur= !cur;
       }
     }
     v.push_back(id);
   }
   int sz=(int)v.size();
   printf("%d\n", sz);
   for (auto x : v) {
     printf("%d ", x);
   }
   cout<<endl;
 }
 return 0;
}


