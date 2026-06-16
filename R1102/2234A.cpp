
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
   scanf("%d", &n);
  //  string s;
  //  cin>>s;
   map<int,int> mp;
   mp.clear();
   for (int i = 1; i <= n; ++i) {
     scanf("%d", &a[i]);
     mp[a[i]]++;
   }
   sort(a+1, a+n+1);
   mp[a[n]]--;
   mp[a[n-1]]--;
   int x,y;
   if (check(a[n], a[n-1], mp)) {
     x = a[n], y = a[n-1];
     printf("%d %d\n", a[n], a[n-1]);
    //  for (int i = 3; i <= n; ++i) {
    //    int r = x%y;
    //    printf("%d ", r);
    //    x = y, y = r;
    //  }
    //  cout<<endl;
   } else {
     puts("-1");
   }
 }
 return 0;
}


