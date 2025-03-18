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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x;
    scanf("%d", &n);
    for (int i = 1; i <= 2*n; ++i) {
        scanf("%lld", &a[i]);
    }
    sort(a+1, a+2*n+1);
    a[2*n+1] = a[2*n]+a[2*n-1];
    for (int i = 1; i < 2*n-1; ++i) {
        if (i&1) a[2*n+1] -= a[i];
        else a[2*n+1] += a[i];
    }
    printf("%lld %lld %lld ", a[2*n], a[2*n+1], a[2*n-1]);
    for (int i = 1; i < 2*n-1; ++i) {
        printf("%lld ", a[i]);
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
