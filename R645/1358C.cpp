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
//#include <priority_queue>
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t;
ll x, y, z, w;
int main() {
  cin>>t;
  for (int cas=1;  cas<=t; ++cas) {
    scanf("%lld%lld%lld%lld", &x, &y, &z, &w);
    ll dx = (z-x);
    ll dy = (w-y);
    ll ans = dx*dy+1;
    printf("%lld\n", ans);
  }
  return 0;
}
