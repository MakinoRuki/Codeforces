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
int a[N];
int b[N];
ll getpw(ll x, ll y) {
    ll res=1;
    while(y) {
        if (y&1) res=res*x%mod;
        x=x*x%mod;
        y/=2;
    }
    return res;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &m, &k);
    int cnt=0,n1=0;
    for (int i = 0; i < k; ++i) {
        int x,y,c;
        scanf("%d%d%d", &x, &y, &c);
        if ((x == 1) && (y == 1)) continue;
        if ((x == 1) && (y == m)) continue;
        if ((x == n) && (y == 1)) continue;
        if ((x == n) && (y == m)) continue;
        if ((x == 1) || (x == n) || (y == 1) || (y == m)) {
            cnt++;
            if (c == 1) n1++;
        }
    }
    int tot = (n-2)*2+(m-2)*2;
    if (tot == cnt) {
        if (n1&1) {
            puts("0");
        } else {
            printf("%lld\n", getpw(2LL, (ll)n*(ll)m-k));
        }
    } else {
        printf("%lld\n", getpw(2LL, (ll)n*(ll)m-k-1));
    }
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
