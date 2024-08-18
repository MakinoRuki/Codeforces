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
#define N 500005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    vector<int> v;
    v.clear();
    ll mx = 0LL;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (i >= 2) {
        v.push_back(a[i] % (2*k));
        mx = max(mx, (ll)a[i]);
      }
    }
    sort(v.begin(), v.end());
    ll ans = -1;
    for (int r = 0; r < k; ++r) {
      ll tmp = (a[1] + r) % (2*k);
      int id1 = lower_bound(v.begin(), v.end(), tmp + 1) - v.begin();
      int id2 = upper_bound(v.begin(), v.end(), tmp + k) - v.begin();
      int id3 = upper_bound(v.begin(), v.end(), tmp - k) - v.begin();
      // if (r == 3) {
      //   cout<<"tmp="<<tmp<<" "<<id1<<" "<<v[id1]<<" "<<id2<<" "<<v[id2]<<endl;
      // }
      if (id1 >= id2 && id3 <= 0) {
        ll res = max(0LL, mx - a[1] - r);
        res = (res + 2*k - 1) / (2*k);
        ans = a[1] + 2LL * k * res + r;
        break;
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
