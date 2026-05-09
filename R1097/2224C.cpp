
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
   map<int,int> mp;
   mp.clear();
   for (int i = 1; i <= n; ++i) {
     scanf("%d", &a[i]);
     mp[a[i]]++;
     //ss.insert(a[i]);
   }
   int mx = (*mp.rbegin()).first;
   a[1] = mx;
   mp[mx]--;
   if (mp[mx] == 0) mp.erase(mx);
   int cur=2;
   for (auto itr : mp) {
     a[cur++] = itr.first;
     itr.second--;
   }
   for (auto itr : mp) {
     for (int i = 1; i <= itr.second; ++i) {
       a[cur++] = itr.first;
     }
   }
   set<int> ss;
   ss.clear();
   int mex=0;
   mx=0;
   ll ans=0;
   for (int i = 1; i <= n; ++i) {
     ss.insert(a[i]);
     mx = max(mx, a[i]);
     while(ss.find(mex) != ss.end()) mex++;
     ans += (ll)mx+(ll)mex;
   }
   printf("%lld\n", ans);
 }
 return 0;
}


