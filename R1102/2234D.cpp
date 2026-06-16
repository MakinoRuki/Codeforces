
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
int b[N];
ll calc(string& s) {
  ll b1=0,b0=0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '1') b1++;
    else b0++;
  }
  return b1*b0;
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
  // ll n;
   scanf("%d%d", &n, &k);
   string s1, s2;
   cin>>s1>>s2;
   string s12="";
   ll n1=0,n2=0,n12=0;
   for (int i = 0; i < n; ++i) {
     int b1=s1[i]-'0';
     int b2=s2[i]-'0';
     int r = b1^b2;
     s12.push_back(r + '0');
   }
   n1 = calc(s1);
   n2 = calc(s2);
   n12 = calc(s12);
   ll ans=0LL;
   if (k%2) {
     ll m = (1LL<<k)+1;
     m/=3;
     ans = n1 * m + n2 * m + n12 * m;
   } else {
     ll m = (1LL<<k)+1;
     m -= 2;
     m /= 3;
     ans = n1 * (m+1) + n2 * (m+1) + n12 * m;
   }
   printf("%lld\n", ans);
 }
 return 0;
}


