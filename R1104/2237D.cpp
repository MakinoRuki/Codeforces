
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
int s0[N], s1[N];
ll cnt[N][3];
int pre[N];
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
   string s;
   cin>>s;
   s0[0]=0;
   s1[0]=0;
   for (int i = 1; i <= n; ++i) {
     s0[i]=s0[i-1];
     s1[i]=s1[i-1];
     int v = s[i-1]-'0';
     if (v == 0) s0[i]++;
     else s1[i]++;
   }
   for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < 3; ++j) {
      cnt[i][j]=0;
    }
   }
   pre[1] = -1;
   for (int i = 2; i <= n; ++i) {
     if (s[i-1] == s[i-2]) pre[i] = i;
     else pre[i] = pre[i-1];
   }
   ll ans = 0LL;
   cnt[0][0]++;
   for (int i = 1; i <= n; ++i) {
     ans++;
     ll dt = s0[i]-s1[i];
     int dt2 = (dt % 3 + 3) % 3;
     int pid = pre[i];
     if (pid > 0) {
       pid -= 2;
       ans += pid+1 - cnt[pid][dt2];
     }
     for (int j = 0; j < 3; ++j) {
       cnt[i][j] = cnt[i-1][j];
     }
     cnt[i][dt2]++;
     //cout<<"i="<<i<<" "<<ans<<endl;
   }
   printf("%lld\n", ans);
 }
 return 0;
}
