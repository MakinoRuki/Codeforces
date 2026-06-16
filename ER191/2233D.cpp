
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
int vis[N];
bool check() {
  for (int i = 1; i <= n; ++i) {
    vis[i] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    if (i == 1 || a[i] != a[i-1]) {
      if (vis[a[i]]) return false;
      vis[a[i]] = i;
    }
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
   scanf("%d", &n);
   for (int i = 1; i <= n; ++i) {
     scanf("%d", &a[i]);
   }
   int l = -1, r= -1;
   map<int, vector<pair<int,int>>> mp;
   mp.clear();
   int cur=-1;
   for (int i = 1; i <= n; ++i) {
     if (i == 1) {
       l = i, r = i;
       cur = a[i];
     } else {
       if (a[i] == a[i-1]) {
         r = i;
       } else {
         mp[cur].push_back(make_pair(l, r));
         cur = a[i];
         l = i, r = i;
       }
     }
   }
   mp[cur].push_back(make_pair(l, r));
   int cnt=0, num=0;
   bool ok=true;
   int cnt2=0;
   for (auto pr : mp) {
     if (pr.second.size() > 1) {
       int sz = (int)pr.second.size();
       if (sz > 3) {
         ok=false;
         break;
       }
       if (sz > 2) {
         cnt2++;
       }
       cnt++;
     }
   }
   if (!ok || cnt2 > 2) {
     puts("No");
     continue;
   }
   if (cnt > 2) {
     puts("No");
     continue;
   }
   vector<int> vv;
   vv.clear();
   for (auto pr : mp) {
     if (pr.second.size() > 1) {
       for (int i = 0; i < pr.second.size(); ++i) {
         int l1 = pr.second[i].first;
         int r1 = pr.second[i].second;
         vv.push_back(l1);
         vv.push_back(r1);
         if (l1-1>=1) vv.push_back(l1-1);
         if (r1+1<=n) vv.push_back(r1+1);
       }
     }
   }
   ok=false;
   map<int,int> mm;
   mm.clear();
   num=0;
   for (int i = 1; i <= n; ++i) {
     if (mm.find(a[i]) == mm.end()) {
       mm[a[i]] = ++num;
     }
   }
   for (int i = 1; i <= n; ++i) {
     a[i] = mm[a[i]];
   }
   if (check()) {
     ok=true;
   } else {
     for (int i = 0; i < vv.size(); ++i) {
        int x= vv[i];
        for (int j = 0; j < vv.size(); ++j) {
          int y=vv[j];
          if (x==y) continue;
          swap(a[x], a[y]);
          if (check()) {
             ok=true;
             break;
          }
          swap(a[x], a[y]);
        }
     }
   }
   

   if (ok) puts("Yes");
   else puts("No");
 }
 return 0;
}
