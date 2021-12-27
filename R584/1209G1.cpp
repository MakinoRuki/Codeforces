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
int n, m, k, q;
int l, r;
int t;
string s;
int a[N];
int bg[N], ed[N];
int cnt[N];
int main() {
  cin>>n>>q;
  memset(bg, -1, sizeof(bg));
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (bg[a[i]] < 0) {
      bg[a[i]] = i;
      ed[a[i]] = i;
    } else {
      ed[a[i]] = i;
    }
  }
  memset(cnt, 0, sizeof(cnt));
  vector<pair<int,int>> rk;
  rk.clear();
  for (int i = 1; i < N; ++i) {
    if (bg[i] >= 1) {
      rk.push_back(make_pair(bg[i], ed[i]));
    }
  }
  sort(rk.begin(), rk.end());
  vector<pair<int,int>> sg;
  sg.clear();
  for (int i = 0; i < rk.size(); ++i) {
    if (sg.empty() || rk[i].first > sg.back().second) {
      sg.push_back(rk[i]);
    } else {
      sg.back().first = min(sg.back().first, rk[i].first);
      sg.back().second = max(sg.back().second, rk[i].second);
    }
  }
  int ans = 0;
  for (int i = 0; i < sg.size(); ++i) {
    int l = sg[i].first;
    int r = sg[i].second;
    int mx = 0;
    for (int j = l; j <= r; ++j) {
      cnt[a[j]]++;
      mx = max(mx, cnt[a[j]]);
    }
    ans += (r-l+1 - mx);
  }
  cout<<ans<<endl;
  return 0;
}
