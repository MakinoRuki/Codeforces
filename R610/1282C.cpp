#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 200005
using namespace std;
typedef long long ll;
int m, n,tt,a,b;
int c[N], t[N];
int main() {
  cin>>m;
  for (int cas=1;cas<=m; ++cas) {
    cin>>n>>tt>>a>>b;
    vector<pair<int, int>> rk;
    rk.clear();
    int e=0, h=0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", c+i);
      if (c[i] == 0) e++;
      else h++;
    }
    for (int i= 0;i < n; ++i) {
      scanf("%d", t+i);
    }
    for (int i = 0; i < n; ++i) {
      rk.push_back(make_pair(t[i], c[i]));
    }
    sort(rk.begin(), rk.end());
    int ans=0;
    int i = 0;
    int he = 0;
    int hh = 0;
    while(i < n) {
      int cnt=he+hh;
      ll tot = rk[i].first-1;
  //    if (i==1) cout<<he<<" "<<hh<<" "<<rk[i].first-1<<endl;
      tot -= (ll)he * (ll)a;
      tot -= (ll)hh * (ll)b;
      if (tot >= 0) {
        int re = e-he;
        int rh = h - hh;
        if (tot >= 0) {
          cnt += min((ll)re, tot / a);
          tot -= min((ll)re, tot/a) * (ll)a;
        }
        if (tot >= 0) {
          cnt += min((ll)rh, tot / b);
          tot -= min((ll)rh, tot/b) * (ll)b;
        }
        ans=max(ans, cnt);
      } else {
        ans = max(ans, 0);
      }
      int j = i;
      while(j < n && rk[j].first == rk[i].first) {
        if (rk[j].second == 0) he++;
        else hh++;
        j++;
      }
      i = j;
    }
    int cnt=he+hh;
    ll tot=tt;
    tot -= (ll)he*(ll)a;
    tot -= (ll)hh*(ll)b;
    if (tot >= 0) {
      int re=e-he;
      int rh =h-hh;
      if (tot >= 0) {
        cnt += min((ll)re, tot / a);
        tot -= min((ll)re, tot/a) * (ll)a;
      }
      if (tot >= 0) {
        cnt += min((ll)rh, tot / b);
        tot -= min((ll)rh, tot/b) * (ll)b;
      }
      ans=max(ans, cnt);
    } else {
      ans = max(ans, 0);
    }
    cout<<ans<<endl;
  }
  return 0;
}
