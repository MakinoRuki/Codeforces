
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
bool vis[N];
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
   set<pair<int,int>> ss;
   ss.clear();
   for (int i = 1; i <= n; ++i) {
     scanf("%d", &a[i]);
     ss.insert(make_pair(a[i], -i));
   }
   while(!ss.empty()) {
     auto pr = *ss.begin();
     ss.erase(pr);
     int id = -pr.second;
     for (int i = id+1; i <= n; ++i) {
       if (a[i] > a[id]) {
         ss.erase(make_pair(a[i], -i));
         a[i] = a[id];
         ss.insert(make_pair(a[i], -i));
         break;
       }
     }
   }
   int tot=0;
   for (int i =1; i <= n; ++i) {
     tot += a[i];
   }
   printf("%d\n", tot);
 }
 return 0;
}
