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
const ll mod2 = 998244353LL;
int n, m, k;
int t;
string s;
ll a[N];
ll ans[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    ll tot=0LL;
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
      tot += a[i];
    }
    ll cnt = (ll)n*(ll)(n+1)/2;
    if (tot % cnt != 0){
      puts("NO");
      continue;
    }
    tot /= cnt;
    int i;
    for (i = 1; i <= n; ++i) {
      ll det = a[i];
      if (i == 1) det -= a[n];
      else det -= a[i-1];
      if (tot < det || ((tot - det) % n != 0)) {
     //   cout<<"i="<<i<<" "<<det<<" "<<tot<<endl;
        break;
      }
      if (tot - det == 0) {
        break;
      }
      ans[i] = (tot - det) / n;
    }
    if (i <= n) {
      puts("NO");
    } else {
      puts("YES");
      for (int i = 1; i <= n; ++i) {
        printf("%lld", ans[i]);
        if (i < n) cout<<" ";
        else cout<<endl;
      }
    }
  }
  return 0;
}
