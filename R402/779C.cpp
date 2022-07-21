#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int b[N];
bool vis[N];
int main() {
  cin>>n>>k;
  vector<pair<int,int>> rk;
  rk.clear();
  memset(vis, false, sizeof(vis));
  for (int i =1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i =1; i <= n; ++i) {
    scanf("%d", &b[i]);
    rk.push_back(make_pair(b[i]-a[i], i));
  }
  sort(rk.begin(), rk.end());
  ll tot=0LL;
  for (int i = 1; i <= k; ++i) {
    int id = rk[rk.size()-i].second;
    vis[id] = true;
    tot += a[id];
  }
  for (int i = k+1; i <= rk.size(); ++i) {
    int id =rk[rk.size()-i].second;
    if (rk[rk.size()-i].first > 0) {
      vis[id] = true;
      tot += a[id];
    } else {
      break;
    }
  }
  for (int i =1 ; i<= n; ++i) {
    if (!vis[i]) tot += b[i];
  }
  cout<<tot<<endl;
  return 0;
}
