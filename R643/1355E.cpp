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
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, a, r, m;
int h[N];
int main() {
  cin>>n>>a>>r>>m;
  ll sum=0LL;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &h[i]);
    sum += h[i];
  }
  sort(h+1, h+1+n);
  ll ans = (ll)r*sum;
  ll pre = 0LL;
  for (int i = 1; i <= n; ++i) {
    ll ls = pre;
    ll rs = sum - pre - h[i];
    ll dl = (i-1)*(ll)h[i]-pre;
    ll dr = rs - (n-i)*(ll)h[i];
    ll res=0LL;
    if (a+r > m) {
      res += min(dl, dr) * m;
      if (dl > dr) {
        res += (dl-dr)*a;
      } else {
        res += (dr-dl) * r;
      }
    } else {
      res += dl * a + dr * r;
    }
    ans = min(ans, res);
    pre += h[i];
  }
  if (a + r <= m) {
    cout<<ans<<endl;
  } else {
    ll avg = sum/n;
    int i;
    for (i = 1; i <= n; ++i) {
      if (avg < h[i]) break;
    }
    if (i > n) cout<<ans<<endl;
    else {
      ll sum2=0LL;
      for (int j = n; j >= i; --j) {
        sum2 += h[j];
      }
      ll det = sum2 - (n-i+1)*avg;
      ll pre = sum - sum2;
      ll need = (i-1)*avg-pre;
      ll res = need*m;
      det -= need;
      res += min(det * r, (det-n+i-1)*m + (n-det)*a);
      ans = min(ans, res);
      cout<<ans<<endl;
    }
  }
  return 0;
}
