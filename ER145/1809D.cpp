#include <iostream>
#include <cstdio>
#include <stdio.h>
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
#include <cstring>
#define N 300005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q, p;
int t;
int num;
int cnt[N];
vector<int> ids;
int main() {
  cin>>t;
  ll c1 = 1000000000000LL;
  ll c0 = c1 + 1;
  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    string s;
    cin>>s;
    n = (int)s.size();
    ids.clear();
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') ids.push_back(i);
    }
    cnt[0] = 0;
    for (int i =1; i <= n; ++i) {
      cnt[i] = cnt[i-1];
      if (s[i-1] == '1') cnt[i]++; 
    }
    ll ans = -1;
    if (ids.empty()) {
      puts("0");
      continue;
    }
    int sz = (int)ids.size();
    for (int i = sz; i >= 0; --i) {
      if (i - 1 >= 0) {
        if (i - 2 >= 0) {
          int id1 = ids[i-2];
          int id2 = ids[i-1];
          ll dt1 = cnt[id1];
          ll dt2 = cnt[id2] - cnt[id1];
       //   cout<<dt1<<" "<<dt2<<endl;
          ll res = (ll)(sz - i + dt1) * c0 + dt2 * c1;
          ans = (ans < 0 ? res : min(ans, res));
        } else {
          int id1 = ids[i-1];
          ll dt1 = cnt[id1];
          ll res = (ll)(sz-i) * c0 + dt1 * c1;
          ans = (ans < 0 ? res : min(ans, res));
        }
      } else {
        ll res = (ll)(sz-i) * c0;
        ans = (ans < 0 ? res : min(ans, res));
      }
    //  cout<<"i="<<i<<" "<<ans<<endl;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
