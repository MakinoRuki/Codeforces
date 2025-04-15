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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &m, &k);
    // [0,mx)每个数至少出现m+1次。
    // mx*m+1>m*k => m*k-m*mx<=n-mx*(m+1)。
    int mx=n/(m+1);
    mx = min(mx, n-m*k);
    int dt=n-mx*(m+1);
    int q = dt/m;
    int r = dt%m;
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < mx; ++j) {
            printf("%d ", j);
        }
        for (int j = 1; j <= q; ++j) {
            printf("%d ", 1000000000);
        }
        if (i <= r) {
            printf("%d ", 1000000000);
        }
    }
    for (int i = 0; i < mx; ++i) {
        printf("%d ", i);
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
