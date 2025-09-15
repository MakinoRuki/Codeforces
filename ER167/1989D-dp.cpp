
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
#define N 2000005
#define M 5002
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
ll dp[N];
int mx[N];
int main() {
 // freopen("data.txt", "r", stdin);
  cin>>n>>m;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i =1 ; i <= n; ++i) {
    scanf("%d", &b[i]);
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &c[i]);
  }
  for (int i = 0; i < N; ++i) {
    dp[i] = 0;
    mx[i]=-1;
  }
  for (int i = 1; i <= n; ++i) {
    if (mx[a[i]] < 0) mx[a[i]] = i;
    else {
      int id=mx[a[i]];
      if (a[i]-b[i] < a[id]-b[id]) {
        mx[a[i]] = i;
      }
    }
  }
  for (int i = 1; i < N; ++i) {
    if (mx[i]<0) mx[i]=mx[i-1];
    else {
      if (mx[i-1]>0) {
        int id1=mx[i-1];
        int id2=mx[i];
        if (a[id1]-b[id1]<=a[id2]-b[id2]) {
          mx[i]=mx[i-1];
        }
      }
    }
    
  }
  for (int i = 1; i < N; ++i) {
    int id=mx[i];
    if (id<0) dp[i]=0;
    else {
      int x=a[id];
      int dt=a[id]-b[id];
      int y = i-((i-x)/dt+1)*dt;
      dp[i] = dp[y]+((i-x)/dt+1)*2LL;
    }
//if (i<=10) cout<<"i="<<i<<" "<<dp[i]<<endl;
  }
  ll ans=0LL;
  for (int i = 1; i <= m; ++i) {
    if (c[i] >= 1000000) {
      int id=mx[1000000];
      if (id<0) continue;
      int x=a[id];
      int dt=a[id]-b[id];
      int y = c[i]-((c[i]-x)/dt+1)*dt;
      ans += ((c[i]-x)/dt+1)*2LL + dp[y];
    } else {
      ans += dp[c[i]];
    }
  }
  printf("%lld\n", ans);
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
