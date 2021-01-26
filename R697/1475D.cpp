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
int t, n, m;
vector<ll> a1, a2;
ll a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    a1.clear();
    a2.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
    }
    for (int i = 1; i <=n; ++i) {
      scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; ++i) {
      if (b[i] == 1) {
        a1.push_back(a[i]);
      } else {
        a2.push_back(a[i]);
      }
    }
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());
    a1.push_back(0);
    a2.push_back(0);
    reverse(a1.begin(), a1.end());
    reverse(a2.begin(), a2.end());
    ll ans = -1;
    for (int i = 1; i < a1.size(); ++i) {
      a1[i] += a1[i-1];
    }
    for (int i = 1; i < a2.size(); ++i) {
      a2[i] += a2[i-1];
    }
    for (int i = 0; i < a1.size(); ++i) {
      if (a1[i] + a2.back() < m) continue;
      int l = 0, r = a2.size()-1;
      while(l < r) {
        int mid=(l+r)/2;
        if (a2[mid]+a1[i] >= m) {
          r = mid;
        } else {
          l = mid+1;
        }
      }
   //   cout<<i<<" "<<r<<endl;
    //  if (i == 2) cout<<a1[i]<<" "<<a2[1]<<" "<<a2[2]<<endl;
      ll cur = 0LL;
      if (r == a2.size()) {
        continue;
      }
      cur = i+2*r;
      ans = (ans < 0 ? cur : min(ans, cur));
    }
    printf("%lld\n", ans);
  }
  return 0;
}
