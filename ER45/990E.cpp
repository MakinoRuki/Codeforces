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
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n,m,k;
int s[N];
int a[N];
bool b[N];
int pos[N];
int main() {
  cin>>n>>m>>k;
  memset(b, false, sizeof(b));
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &s[i]);
    b[s[i]] = true;
  }
  for (int i = 1; i <= k; ++i) {
    scanf("%d", &a[i]);
  }
  if (m > 0 && s[1] == 0) {
    cout<<-1<<endl;
    return 0;
  }
  memset(pos, -1, sizeof(pos));
  int idx = 0;
  for (int i = 0; i < n; ++i) {
    if (!b[i]) idx = i;
    pos[i] = idx;
  }
  ll ans = -1;
  for (int i = 1; i <= k; ++i) {
    int cur=0;
    ll cnt=0;
    bool ok=true;
    while(cur < n) {
      int cur2=cur;
      cur += i;
      cnt++;
      if (cur >= n) break;
      cur = pos[cur];
      if (cur <= cur2) {
        ok = false;
        break;
      }
    }
  //  if (i == 1) cout<<"v="<<ok<<" "<<cnt<<endl;
    if (!ok) continue;
    ll res = (ll)a[i] * cnt;
    ans = (ans < 0 ? res : min(ans, res));
  }
  cout<<ans<<endl;
  return 0;
}
