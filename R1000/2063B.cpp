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
#define N 200005
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
ll check(int l1, int r1, int l2, int r2) {
  ll tot=0LL;
  set<pair<int,int>> ss;
  ss.clear();
  for (int i = l2; i <= r2; ++i) {
    tot += a[i];
    ss.insert(make_pair(a[i], i));
  }
  vector<int> v;
  v.clear();
  for (int i = l1; i <= r1; ++i) {
    v.push_back(a[i]);
  }
  sort(v.begin(), v.end());
  for (auto x : v) {
    if (!ss.empty() && x < (*ss.rbegin()).first) {
      tot -= (*ss.rbegin()).first;
      ss.erase(*ss.rbegin());
      tot += x;
    } else {
      break;
    }
  }
  return tot;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int l, r;
    scanf("%d%d%d", &n, &l, &r);
    ll ans=0LL;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (i>=l && i<=r) ans += a[i];
    }
    ll res1=check(1, l-1, l, r);
    ll res2=check(r+1, n, l, r);
    ans = min(ans, min(res1, res2));
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
