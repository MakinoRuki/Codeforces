

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
bool check(int x, int y, map<int,int> mp) {
  for (int i = 3; i <= n; ++i) {
    int r = x%y;
 //   cout<<"i="<<i<<" "<<r<<endl;
    if (mp.find(r) == mp.end() || mp[r] == 0) return false;
    mp[r]--;
    x = y, y = r;
  }
  return true;
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
 //  ll x, y;
   ll n;
   scanf("%lld", &n);
  //  string s;
  //  cin>>s;
   ll z = 0;
   ll r = n%12;
   if (r <= 9) {
     printf("%lld %lld\n", r, n-r);
   } else if (r == 11) {
     printf("%lld %lld\n", 11LL, n- 11);
   } else {
     if (n == 10) puts("-1");
     else {
       printf("%lld %lld\n", 22LL, n-22);
     }
   }
 }
 return 0;
}


