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
#define N 1000005
#define M 1002
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
int d[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    ll n0=0,n1=0;
    ll cnt=0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
        if (a[i] > c[i]) {
            n0 += a[i]-c[i];
        }
        if (b[i] > d[i]) {
            n1 += b[i]-d[i];
        }
        if (a[i]> 0 && c[i]>0 && b[i] > d[i]) {
            cnt += min(a[i], c[i]);
        }
    }
    cnt += n0+n1;
    printf("%lld\n", cnt);
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
