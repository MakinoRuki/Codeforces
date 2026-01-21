
#include <iostream>
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
#define N 500005
#define M 10002
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int b[N];
int c[N];
int tt[N];
ll cur[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll h;
    cin>>n>>m>>h;
    for (int i =1; i <= n; ++i) {
      scanf("%d", &a[i]);
      cur[i] = a[i];
      tt[i]=0;
    }
    int pre=0;
    for (int i = 1; i <= m; ++i) {
      scanf("%d%d", &b[i], &c[i]);
      if (tt[b[i]]<pre) {
        cur[b[i]] = a[b[i]]; 
      }
      tt[b[i]] = i;
      cur[b[i]] += c[i];
      if (cur[b[i]] > h) {
        cur[b[i]] = a[b[i]];
        pre=i;
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (tt[i]<pre) {
        cur[i] = a[i];
      }
    }
    for (int i = 1; i <= n; ++i) {
      printf("%lld ", cur[i]);
    }
    cout<<endl;
  }

  

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
