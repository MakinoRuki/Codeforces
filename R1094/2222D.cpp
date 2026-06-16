
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
ll sum[N];
int p[N];
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
   sum[0]=0;
   for (int i = 1; i <= n; ++i) {
     scanf("%d", &a[i]);
     sum[i]=sum[i-1]+a[i];
   }
   vector<pair<ll, int>> rk;
   rk.clear();
   for (int i = 1; i <= n; ++i) {
     ll v = sum[i]-a[i];
     rk.push_back(make_pair(v, i));
   }
   sort(rk.begin(), rk.end(), [](const pair<ll,int>& p1, const pair<ll,int>& p2) {
     if (p1.first == p2.first) {
       return p1.second > p2.second;
     }
     return p1.first > p2.first;
   });
   for (int i = 1; i <= n; ++i) {
     int id = rk[i-1].second;
     p[id] = i;
   }
   for (int i = 1; i <= n; ++i) {
     printf("%d ", p[i]);
   }
   cout<<endl;
 }
 return 0;
}
