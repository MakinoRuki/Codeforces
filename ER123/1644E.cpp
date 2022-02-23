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
#define M 202
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
vector<pair<int,int>> ps;
bool hd[N], hr[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    cin>>s;
    ll tot=0LL;
    ll cr = 0, cd = 0;
    ps.clear();
    int x=1,y=1;
    m = (int)s.size();
    for (int i = 0; i <= m; ++i) {
      hd[i] = false;
      hr[i] = false;
    }
    for (int i = 0; i < m; ++i) {
      if (i>0) {
        hd[i] = hd[i-1];
        hr[i] = hr[i-1];
      }
      if (s[i] == 'D') {
        x++;
        hd[i] = true;
      } else {
        y++;
        hr[i] = true;
      }
      ps.push_back(make_pair(x, y));
    }
    for (int i = m-1; i >= 0; --i) {
      ll cx = ps[i].first;
      ll cy = ps[i].second;
      if (i == m-1) {
        ll d1 = n-cx+1;
        ll d2 = n-cy+1;
        if (hd[i] && hr[i]) tot += d1 * d2;
        else if (hd[i]) tot += d1;
        else if (hr[i]) tot += d2;
        else tot++;
      } else {
        if (s[i+1] == 'R') {
          ll det = n-cx-cd;
          if (hd[i]) tot += det+1;
          else tot++;
        } else {
          ll det = n-cy-cr;
          if (hr[i]) tot += det+1;
          else tot++;
        }
      }
      if (s[i] == 'R') cr++;
      else cd++;
    //  cout<<"x="<<i<<" "<<tot<<endl;
    }
    tot++;
    printf("%lld\n", tot);
  }
  return 0;
}
