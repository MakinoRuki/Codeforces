#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
int a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int l1 = -1, lp = -1;
    int r1 = -1, rp = -1;
    map<pair<int,int>, int> mp;
    mp.clear();
    vector<ll> ans;
    for (int i = 1; i <= n; ++i) {
      int l, r, c;
      scanf("%d%d%d", &l, &r, &c);
      if (l1 < 0 || l < l1) {
        l1 = l;
        lp = c;
      } else if (l == l1 && c < lp) {
        lp = c;
      }
      if (r1 < 0 || r > r1) {
        r1 = r;
        rp = c;
      } else if (r == r1 && c < rp) {
        rp = c;
      }
    //  cout<<"i="<<i<<" "<<l1<<" "<<r1<<" "<<lp<<" "<<rp<<endl;
      if (mp.find(make_pair(l, r)) == mp.end()) {
        mp[make_pair(l, r)] = c;
      } else {
        mp[make_pair(l, r)] = min(mp[make_pair(l, r)], c);
      }
     // cout<<p3<<endl;
      ll res = -1;
      if (mp.find(make_pair(l1, r1)) != mp.end()) res = mp[make_pair(l1, r1)];
    //  cout<<"res="<<res<<endl;
      res = (res < 0 ? (ll)lp+(ll)rp : min(res, (ll)lp+(ll)rp));
    //  cout<<res<<endl;
      ans.push_back(res);
    }
    for (int i = 0; i < n; ++i) {
      printf("%lld\n", ans[i]);
    }
  }
  return 0;
}
