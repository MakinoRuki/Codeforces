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
#define N 300005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    string s;
    cin>>s;
    int mx=0;
    int cnt=0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '1') {
        cnt++;
      } else {
        mx=max(mx, cnt);
        cnt=0;
      }
    }
    if (cnt>0) mx=max(mx, cnt);
    ll ans=0LL;
    if (mx < (int)s.size()) {
      int lc=0;
      for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '1') lc++;
        else break;
      }
      int rc=0;
      for (int i = s.size()-1; i >= 0; --i) {
        if (s[i] == '1') rc++;
        else break;
      }
      mx=max(mx, lc+rc);
      if (mx%2) {
        ans=max(ans, (ll)((mx+1)/2)*(ll)((mx+1)/2));
      } else {
        ans=max(ans, (ll)(mx/2+1)*(ll)(mx/2));
      }
    } else {
      ans=max(ans, (ll)mx*(ll)mx);
    }
    
    printf("%lld\n", ans);
  }
  return 0;
}
