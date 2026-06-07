
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
int ln,rn;
ll getpw(ll x, ll y) {
  ll res=1LL;
  while(y) {
    if (y&1) res=res*x%mod2;
    x=x*x%mod2;
    y/=2;
  }
  return res;
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
   scanf("%d", &n);
   for (int i = 1; i <= n; ++i) {
     scanf("%d", &a[i]);
   }
   for (int i = 1; i <= n; ++i) {
     scanf("%d", &b[i]);
   }
   vector<pair<int,int>> v1;
   vector<pair<int,int>> v2;
   for (int i = 1; i <= n; ++i) {
    for (int j =i+1; j <= n; ++j) {
      v1.push_back(make_pair(a[i], a[j]));
    }
   }
   sort(v1.begin(), v1.end(), [](const pair<int,int>& p1, const pair<int,int>& p2) {
     return (ll)p1.first * (ll)p2.second < (ll)p2.first * (ll)p1.second;
   });
   for (int i =1; i <= n; ++i) {
     for (int j = 1; j <= n; ++j) {
       if (i == j) continue;
       v2.push_back(make_pair(b[i], b[j]));
     }
   }
   sort(v2.begin(), v2.end(), [](const pair<int,int>& p1, const pair<int,int>& p2) {
     return (ll)p1.first * (ll)p2.second < (ll)p2.first * (ll)p1.second;
   });
  //  for (auto pr : v1) {
  //    cout<<"p1="<<pr.first<<" "<<pr.second<<endl;
  //  }
  //  for (auto pr : v2) {
  //    cout<<"p2="<<pr.first<<" "<<pr.second<<endl;
  //  }
   int j = 0;
   ll sum=0LL;
   for (int i = 1; i <= v1.size(); ++i) {
     while(j < v2.size() && (ll)v1[i-1].first * (ll)v2[j].second > (ll)v1[i-1].second * (ll)v2[j].first) {
       j++;
     }
   //  cout<<"i="<<i<<" "<<j<<endl;
     sum += j;
   }
   ll ans = sum % mod2 * getpw((ll)n*(ll)(n-1), mod2-2) % mod2;
   printf("%lld\n", ans);
 }
 return 0;
}


