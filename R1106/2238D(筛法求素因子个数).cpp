
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
int pm[N];
int cnt[N], sum[N];
int nxt[N];
int main() {
 for (int i = 0; i < N; ++i) {
   pm[i]=0;
   cnt[i]=0,sum[i]=0;
 }
 for (int i = 2; i < N; ++i) {
   if (pm[i] == 0) {
     for (int j = i; j < N; j += i) {
       if (pm[j] == 0) pm[j]=i;
     }
   }
   if (pm[i] == i) {
     cnt[i] = 1;
     sum[i] = 1;
   } else {
     int dt = i/pm[i];
     if (pm[i] == pm[dt]) {
       nxt[i] = nxt[dt];
       cnt[i] = cnt[nxt[dt]]+1;
       sum[i] = sum[dt]+1;
     } else {
       nxt[i] = dt;
       cnt[i] = cnt[dt]+1;
       sum[i] = sum[dt]+1;
     }
   }
 }
 cin>>t;
 for (int cas=1; cas<=t; ++cas) {
 //  ll x, y;
   scanf("%d", &n);
 //  string s;
   int ans=cnt[n]+sum[n]-1;
   printf("%d\n", ans);
 }
 return 0;
}
