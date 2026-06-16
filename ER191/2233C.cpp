
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
   scanf("%d%d", &n, &k);
   string s;
   cin>>s;
   string ans="";
   int anss=inf;
   // 选一个对应右括号最多的左括号或者对应左括号最多的右括号。
   for (int l = 0; l <= k; ++l) {
     int r = k - l;
     int res=0;
     string v = string(n, '0');
     int cnt=0;
     for (int i = 0; i < n; ++i) {
       if (s[i] == '(') {
         if (cnt < l) {
           cnt++;
           v[i] = '1';
         }
       }
     }
     cnt=0;
     for (int i = n-1; i >= 0; --i) {
       if (s[i] == ')') {
         if (cnt < r) {
           cnt++;
           v[i] = '1';
         }
       }
     }
     vector<int> st;
     st.clear();
     for (int i = 0; i < n; ++i) {
       if (s[i] == '(') {
         if (v[i] == '0') st.push_back(i);
       } else {
         if (v[i] == '0') {
           if (!st.empty()) {
             res+=2;
             st.pop_back();
           }
         }
       }
     }
     if (res < anss) {
       anss = res;
       ans = v;
     }
   }
   cout<<ans<<endl;
 }
 return 0;
}
