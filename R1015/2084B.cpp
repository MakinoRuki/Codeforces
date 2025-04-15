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
#define M 750
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
ll a[N];
ll getgcd(ll x, ll y) {
    return y == 0 ? x: getgcd(y, x%y);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }
    sort(a+1, a+n+1);
    if (a[1] == a[2]) {
        puts("Yes");
        continue;
    }
    ll g = 0;
    for (int i = 2; i <= n; ++i) {
        if (a[i] % a[1]) continue;
        g = getgcd(a[i]/a[1], g);
    }
    if (g == 1) {
        puts("Yes");
    } else {
        puts("No");
    }
    // if (g > a[1]) {
    //     ll d = g/a[1];
    //     int cnt=0;
    //     for (int i = 2; i <= n; ++i) {
    //         if (a[i] % a[1]) continue;
    //         if (getgcd(a[i], d) == 1) {
    //             cnt++;
    //         }
    //     }
    //     if (cnt > 1) {
    //         puts("Yes");
    //     } else {
    //         puts("No");
    //     }
    // } else if (g == a[1]) {
    //     puts("Yes");
    // } else {
    //     puts("No");
    // }
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
