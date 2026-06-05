
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
   scanf("%d%lld%lld", &n, &x, &y);
   string s;
   cin>>s;
   ll tt=0, ss=0;
   ll aa=0;
   ll ans=0;
   for (int i = 0; i < n; ++i) {
    if (s[i] == 'E') {
      if (tt*y > ss) {
        ans++;
        ss++;
      } else {
        if (aa && tt < x && y > 1) {
          aa--;
          tt++;
          ss++;
          ans++;
        }
      }
    } else if (s[i] == 'I') {
      if (tt < x) {
        tt++;
        ss++;
        ans++;
      }
    } else {
      if (tt == 0) {
        tt++;
        ss++;
        ans++;
      } else {
        if (tt * y > ss) {
          ss++;
          ans++;
          // only when A seated in nonempty table can be used later for E.
          aa++;
        } else if (tt < x) {
          tt++;
          ss++;
          ans++;
        }
      }
    }
   // cout<<"ans="<<ans<<endl;
   }
  // ll dt = min(x*y-ss, aa);
  // ans += dt;
   printf("%lld\n", ans);
 }
 return 0;
}


