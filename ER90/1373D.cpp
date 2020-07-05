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
#define N 200005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, p;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n;
    ll tot = 0LL;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
      if (i%2==0) tot += a[i];
    }
    ll ans=tot;
    set<ll> s1;
    set<ll> s2;
    s1.insert(-a[0]);
    s2.insert(0);
    ll sum1 = -a[0];
    ll sum2 = 0;
    for (int i = 1; i < n; ++i) {
      if (i%2) {
        sum2 += a[i]-a[i-1];
        auto pre = (*s2.begin());
        if (tot + sum2-pre > ans) {
          ans = tot+sum2-pre;
        }
        s2.insert(sum2);
      } else {
        sum1 += a[i-1]-a[i];
        auto pre = (*s1.begin());
        if (tot + sum1-pre > ans) {
          ans = tot+sum1-pre;
        }
        s1.insert(sum1);
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
