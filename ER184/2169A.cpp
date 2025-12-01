
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
#define M 8002
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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x;
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    ll s0=0,s1=0,s2=0;
    for (int i = 1; i <= n; ++i) {
      if (a[i] < x) s0++;
      else if (a[i]==x) s1++;
      else s2++;
    }
    ll ans=0LL;
    ll y=x;
    if (s0 < s2) {
      ans=s2,y=x+1;
    } else {
      ans=s0,y=x-1;
    }
    printf("%lld\n", y);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
