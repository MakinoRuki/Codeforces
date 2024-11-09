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
#define M 405
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, p;
int t;
ll a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<pair<ll, ll>> v;
    v.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
      v.push_back(make_pair(a[i]+i-1, i-1));
    }
    sort(v.begin(), v.end());
    set<ll> ss;
    ss.clear();
    ss.insert(n);
    ll ans = n;
    for (int i = 0; i < v.size(); ++i) {
      ll len = v[i].first;
      ll dt = v[i].second;
      if (ss.find(len) != ss.end()) {
        ss.insert(len + dt);
        ans = max(ans, len+dt);
      }
    }
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

