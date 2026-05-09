
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
int dp[M];
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
   vector<int> rk;
   rk.clear();
   for (int i = 1; i <= n; ++i) {
     scanf("%d", &a[i]);
     rk.push_back(a[i]);
   }
   sort(rk.begin(), rk.end());
   int pre=0;
   int cur=0;
   int med = -1;
   while(cur < rk.size()) {
     int i;
     int cnt=0;
     for (i = cur; i < rk.size(); ++i) {
       if (rk[i] == rk[cur]) cnt++;
       else break;
     }
     int rem=n-pre-cnt;
     if (abs(pre-rem) < cnt) {
       med = rk[cur];
       break;
     }
     pre += cnt;
     cur = i;
   }
   if (med < 0) {
     puts("0");
     continue;
   }
   for (int i = 0; i <= n; ++i) {
     dp[i] = -1;
   }
   dp[0] = 0;
   for (int i = 0; i < n; ++i) {
     if (dp[i] >= 0) {
       int l = 0, r = 0, nn = 0;
       for (int j = i+1; j <= n; ++j) {
         if (a[j] < med) l++;
         else if (a[j] == med) nn++;
         else r++;
         if ((j-i)%2 && abs(l-r) < nn) {
           dp[j] = max(dp[j], dp[i]+1);
         }
       }
     }
   }
   printf("%d\n", dp[n]);
 }
 return 0;
}


