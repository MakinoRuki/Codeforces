/* 既然可以旋转匹配，那么哪一维对哪一维其实不重要，因此统一min(L,W)放前max(L,W)放后，然后按照第一维排序。
然后(a,b)和(c,d)，已知a<=b,c<=d那么c是四个数最小的，无论它跟a还是b对应都会取到它，因此选择max(a,b)跟d对应即可，也就是b跟d对应。
因此就是前面所有b的max跟当前d对应，乘以c得到面积。 */

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
#define N 3000005
#define M 50
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
vector<pair<ll,ll>> lw;
int main() {
//  cin>>t;
//  for (int cas=1; cas<=t; ++cas) {
    int x,y;
    scanf("%d", &n);
    ll ans = 0LL;
    lw.clear();
    for (int i = 1; i <= n; ++i) {
      ll l,w;
      scanf("%lld%lld", &l, &w);
      lw.push_back(make_pair(min(l,w), max(l,w)));
      ans = max(ans, l*w);
    }
    sort(lw.begin(), lw.end(), [](const pair<ll,ll>& p1, const pair<ll,ll>& p2) {
      return p1.first > p2.first;
    });
    ll mx=0LL;
    for (int i = 0; i < n; ++i) {
     // cout<<"i="<<i<<" "<<mx<<" "<<lw[i].second<<" "<<lw[i].first<<endl;
      ll tmp = min(mx, lw[i].second) * lw[i].first * 2LL;
      ans = max(ans, tmp);
      mx = max(mx, lw[i].second);
    }
    if (ans % 2) printf("%lld.5\n", ans/2);
    else printf("%lld.0\n", ans/2);
 // }
  return 0;
}
