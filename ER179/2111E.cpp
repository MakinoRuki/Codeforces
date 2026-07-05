
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
#define M 1805
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
set<int> ss[3][3];
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
   scanf("%d%d", &n, &q);
   string s;
   cin>>s;
   for (int i= 0; i < 3; ++i) {
     for (int j = 0; j < 3; ++j) {
       ss[i][j].clear();
     }
   }
   for (int i = 1; i <= q; ++i) {
     string c1, c2;
     cin>>c1>>c2;
     ss[c1[0]-'a'][c2[0]-'a'].insert(i);
   }
   for (int i = 0; i < n; ++i) {
     if (s[i] == 'c') {
       if (!ss[2][0].empty()) {
         s[i] = 'a';
         ss[2][0].erase(*ss[2][0].begin());
       } else if (!ss[2][1].empty()) {
         auto id = *ss[2][1].begin();
         if (!ss[1][0].empty()) {
           auto itr = ss[1][0].upper_bound(id);
           if (itr != ss[1][0].end()) {
             s[i] = 'a';
             ss[1][0].erase(itr);
             ss[2][1].erase(id);
             continue;
           }
         }
         s[i] = 'b';
         ss[2][1].erase(*ss[2][1].begin());
       }
     } else if (s[i] == 'b') {
       if (!ss[1][0].empty()) {
         s[i] = 'a';
         ss[1][0].erase(*ss[1][0].begin());
       } else if (!ss[1][2].empty()) {
         auto id = *ss[1][2].begin();
         if (!ss[2][0].empty()) {
           auto itr = ss[2][0].upper_bound(id);
           if (itr != ss[2][0].end()) {
             s[i] = 'a';
             ss[1][2].erase(id);
             ss[2][0].erase(itr);
           }
         }
       }
     }
   }
   cout<<s<<endl;
 }
 return 0;
}
