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
#define N 600005
#define M 205
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
    ll m;
    scanf("%d%lld", &x, &m);
    int p = 0;
    while((1<<p) <= x) {
        p++;
    }
    ll ans=0LL;
    ll cy=0, cx=0, cxy = 0;
    for (int i = 1; i < min(m+1, (1LL<<p)); ++i) {
        ll z = x ^ i;
        if ((z%i)==0) {
            cy++;
        }
        // if ((z%x)==0) {
        //     cx++;
        // }
        if ((z%x)==0 && (z%i)==0) {
            cxy++;
        }
    }
  //  cout<<cy<<" "<<cxy<<endl;
    if (m>=x) {
        cx = (m-x)/x+1; //max((m-x)/x-1, 0LL);
        if (x<=m-x) cx--;
    }
  //  cout<<"cx="<<cx<<endl;
    for (ll i = max(0LL, m-x+1); i <= m+3*x; ++i) {
        if (((i%x)==0) && (i^x)>=1 && (i^x)<=m) {
            cx++;
        }
    }
    ans = cx+cy-cxy;
    printf("%lld\n", ans);
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
