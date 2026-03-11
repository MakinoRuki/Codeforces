/* 首先每个人自己的序列，先按照下降点切分成一些block。每个block之间是必然要有一个坏对的，因此希望在这之间尽量多塞数字。
然后把各个人的按照block合并，先把所有人的第一个block从小到大merge，再看第二个block的，以此类推。
具体实现就是先按照每个任务在各自人的block数排序，然后按照值从小到大排序。 */

#include <iostream>
#include <sstream>
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
#define N 3000005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod1 = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 1000003;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
int ans[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d", &n);
  // }
  cin>>n;
  vector<pair<pair<int,ll>,int>> rk;
  rk.clear();
  int ans=0;
  ll tot=0LL;
  for (int i = 1; i <= n; ++i) {
    ll z,x,y,m;
    scanf("%d%lld%lld%lld%lld", &k, &z, &x, &y, &m);
    int cur=0;
    tot += k;
    rk.push_back(make_pair(make_pair(cur, z), i));
    for (int j = 2; j <= k; ++j) {
      ll z2 = (z * x + y) % m;
      if (z2 < z) {
        cur++;
      }
      z = z2;
      rk.push_back(make_pair(make_pair(cur, z), i));
    }
    ans = max(ans, cur);
  }
  sort(rk.begin(), rk.end());
  printf("%d\n", ans);
  if (tot <= 200000) {
    for (auto pr : rk) {
      printf("%lld %d\n", pr.first.second, pr.second);
    }
  }
  return 0;
}
 
