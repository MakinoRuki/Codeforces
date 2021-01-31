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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n;
ll c[N];
int a[N], b[N];
ll getres(vector<int>& ids) {
  ll sum = 0LL;
  ll res = 0LL;
  for (int i = ids.size()-1; i >= 0; --i) {
  //  cout<<"id="<<ids[i]<<endl;
    int id = ids[i];
    if (id > 1) {
      //if (id == 2) cout<<"x="<<c[i]<<" "<<b[i]<<" "<<a[i]<<endl;
      res = max(res, c[id] + (ll)abs(b[id]-a[id])+1 + sum);
      sum += c[id] - ((ll)abs(b[id]-a[id])-1);
      if (sum < 0) sum = 0;
    }
  }
//  cout<<"res="<<res<<endl;
  return res;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &c[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
    }
    vector<int> ids;
    ids.clear();
    ll ans = 0LL;
    for (int i = 1; i <= n; ++i) {
      if (i == 1) {
        ids.push_back(i);
      } else {
        int det = abs(b[i]-a[i])+1;
        if (det == 1) {
          ans = max(ans, getres(ids));
          ids.clear();
        }
        ids.push_back(i);
      }
    }
    ans = max(ans, getres(ids));
    printf("%lld\n", ans);
  }
  return 0;
}
