
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
int a[M];
int b[M];
ll check(ll tx, vector<int>& ds) {
  ll tmp=0LL;
  for (auto d : ds) {
    tmp = tmp*10LL+d;
  }
  return abs(tmp-tx);
}
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
   scanf("%lld%d", &x, &n);
   for (int i = 0; i <= 10; ++i) {
     b[i] = 0;
   }
   for (int i = 1; i <= n; ++i) {
     scanf("%d", &a[i]);
     b[a[i]] = 1;
   }
   if (x == 0) {
     printf("%d\n", a[1]);
     continue;
   }
   vector<int> ds;
   ds.clear();
   ll tx = x;
   while(x) {
     ds.push_back(x%10);
     x/=10;
   }
   reverse(ds.begin(), ds.end());
   int sz = (int)ds.size();
   vector<int> vv;
   vv.clear();
   ll ans=(1LL<<61)-1;
 //  cout<<"ans="<<ans<<endl;
   if (a[1] == 0) {
     if (n > 1) {
       vv.push_back(a[2]);
       for (int i = 1; i <= sz; ++i) {
         vv.push_back(a[1]);
       }
       ans = min(ans, check(tx, vv));
     }
   } else {
     for (int i = 1; i <= sz+1; ++i) vv.push_back(a[1]);
     ans=min(ans, check(tx, vv));
   }
 //  cout<<"ans="<<ans<<endl;
   vv.clear();
   if (sz-1>0) {
     for (int i = 1; i <= sz-1; ++i) {
       vv.push_back(a[n]);
     }
     if (vv.size()<=1 || vv[0]!=0) {
       ans=min(ans, check(tx, vv));
     }
   }
//   cout<<"ans="<<ans<<endl;
   vv.clear();
   int i;
   for (i = 0; i < sz; ++i) {
  //  cout<<"i="<<i<<" "<<ds[i]<<endl;
     vv.clear();
     int cc=-1;
     for (int j = 1; j <= n; ++j) {
       if (a[j] > ds[i]) {
        cc = a[j];
        break;
       }
     }
     if (cc >= 0) {
       for (int j = 0; j < i; ++j) vv.push_back(ds[j]);
       vv.push_back(cc);
       for (int j = i+1; j < sz; ++j) vv.push_back(a[1]);
       ans = min(ans, check(tx, vv));
       vv.clear();
     }
     vv.clear();
     cc = -1;
     for (int j = n; j >= 1; --j) {
       if (a[j] < ds[i]) {
         cc = a[j];
         break;
       }
     }
   //  if (i==0) cout<<"cc="<<ds[i]<<" "<<cc<<endl;
     if (cc >= 0) {
       for (int j = 0; j < i; ++j) vv.push_back(ds[j]);
       vv.push_back(cc);
       for (int j = i+1; j < sz; ++j) vv.push_back(a[n]);
     //  cout<<"vv="<<check(tx, vv)<<endl;
       ans=min(ans, check(tx, vv));
       vv.clear();
     }
     if (!b[ds[i]]) break;
   }
   if (i >= sz) ans = 0;
   printf("%lld\n", ans);
 }
 return 0;
}


