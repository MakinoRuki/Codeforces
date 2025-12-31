
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
#define M 105
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const ll mod3 = 1000003;
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
    scanf("%d", &n);
    ll sum=0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      sum += a[i];
    }
    sort(a+1, a+n+1);
    int id=1;
    while(id <= n && a[id] == 0) {
      id++;
    }
    if (id > n) puts("0");
    else {
      ll dt = sum - (n-id+1);
      if (dt >= n-1)
      printf("%d\n", n-id+1);
      else {
        dt = n-1-dt;
        ll res=n-id+1-dt;
        printf("%lld\n", res);
      }
    }
  }
  return 0;
}
