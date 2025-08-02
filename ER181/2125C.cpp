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
int sx, sy, ex, ey;
int a[N];
int cnt[30];
ll l,r;
vector<int> ps = {2,3,5,7,6,10,14,15,21,35,30,105,70,42,210};
ll calc(int id) {
  return r/ps[id]-(l-1)/ps[id];
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%lld%lld", &l, &r);
    ll ans=r-l+1;
    ans -= calc(0)+calc(1)+calc(2)+calc(3);
    for (int i = 4; i <= 9; ++i) {
      ans += calc(i);
    }
    for (int i = 10; i <= 13; ++i) {
      ans -= calc(i);
    }
    ans += calc(14);
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
