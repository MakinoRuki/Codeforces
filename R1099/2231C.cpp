
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
   map<int, ll> st;
   map<int, int> cnt;
   st.clear();
   cnt.clear();
   for (int i = 1; i <= n; ++i) {
     if (a[i] == 1) {
       st[1] += 0;
       cnt[1]++;
       st[2] += 1;
       cnt[2]++;
       continue;
     }
     int cur=a[i];
     int num=0;
     while(true) {
       if (i == 1 || st.find(cur) != st.end()) {
         st[cur] += num;
         cnt[cur]++;
       }
       if (cur == 1) break;
       if (cur %2) cur++;
       else cur/=2;
       num++;
     }
   //  cout<<"i="<<i<<" "<<a[i]<<endl;
   }
   ll ans = (1LL<<61)-1;
   for (auto pr : st) {
     int x = pr.first;
   //  cout<<"x="<<pr.first<<" "<<pr.second<<endl;
     if (cnt.find(x) != cnt.end() && cnt[x] == n) {
       ans = min(ans, pr.second);
     }
   }
   printf("%lld\n", ans);
 }
 return 0;
}


