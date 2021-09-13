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
#define M 12
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
string s;
int hs[N], hmx[N], hmn[N];
int vs[N], vmx[N], vmn[N];
ll getans(int lb, int rb, int sum, int add, int lb2, int rb2, ll det) {
  lb = min(lb, sum+add);
  rb = max(rb, sum+add);
  lb = min(lb, lb2+add);
  rb = max(rb, rb2+add);
  return (ll)(rb-lb+1)*(ll)det;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>s;
    n = (int)s.size();
    hs[0] = 0;
    vs[0] = 0;
    for (int i = 1; i <= n; ++i) {
      hs[i] = hs[i-1];
      vs[i] = vs[i-1];
      if (s[i-1] == 'D') {
        hs[i]++;
      } else if (s[i-1] == 'A') {
        hs[i]--;
      } else if (s[i-1] == 'W') {
        vs[i]++;
      } else {
        vs[i]--;
      }
    }
    for (int i = n; i >= 0; --i) {
      hmx[i] = hmn[i] = hs[i];
      vmx[i] = vmn[i] = vs[i];
      if (i < n) {
        hmx[i] = max(hmx[i], hmx[i+1]);
        hmn[i] = min(hmn[i], hmn[i+1]);
        vmx[i] = max(vmx[i], vmx[i+1]);
        vmn[i] = min(vmn[i], vmn[i+1]);
      }
    }
    ll ans = (ll)(hmx[0]-hmn[0]+1)*(ll)(vmx[0]-vmn[0]+1);
  //  cout<<ans<<endl;
    int hl = 0, hr = 0;
    int hs2 = 0;
    int vl = 0, vr = 0;
    int vs2 = 0;
    for (int i = 0; i <= n; ++i) {
      ans = min(ans, getans(hl, hr, hs2, 1, (i<n?hmn[i+1]:0), (i<n?hmx[i+1]:0), vmx[0]-vmn[0]+1));
    //  cout<<i<<" "<<ans<<endl;
      ans = min(ans, getans(hl, hr, hs2, -1, (i<n?hmn[i+1]:0), (i<n?hmx[i+1]:0), vmx[0]-vmn[0]+1));
     // cout<<i<<" "<<ans<<endl;
      ans = min(ans, getans(vl, vr, vs2, 1, (i<n?vmn[i+1]:0), (i<n?vmx[i+1]:0), hmx[0]-hmn[0]+1));
     // cout<<i<<" "<<ans<<endl;
      ans = min(ans, getans(vl, vr, vs2, -1, (i<n?vmn[i+1]:0), (i<n?vmx[i+1]:0), hmx[0]-hmn[0]+1));
     // cout<<i<<" "<<ans<<endl;
      hl = min(hl, hs[i+1]);
      hr = max(hr, hs[i+1]);
      hs2 = hs[i+1];
      vl = min(vl, vs[i+1]);
      vr = max(vr, vs[i+1]);
      vs2 = vs[i+1];
    }
    printf("%lld\n", ans);
  }
  return 0;
}
