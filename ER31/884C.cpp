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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, q, k;
int t;
int p[N];
bool vis[N];
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &p[i]);
  }
  memset(vis, false, sizeof(vis));
  vector<int> ls;
  ls.clear();
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      int cur = p[i];
      int len = 1;
      vis[i] = true;
      while(cur != i) {
        len++;
        vis[cur] = true;
        cur = p[cur];
      }
      ls.push_back(len);
    }
  }
  sort(ls.begin(), ls.end());
  ll tot=0LL;
  if (ls.size() == 1) {
    tot = (ll)n*(ll)n;
  } else {
    int sz = (int)ls.size();
    ls[sz-2] += ls[sz-1];
    for (int i = 0; i < sz-1; ++i) {
      tot += (ll)ls[i] * (ll)ls[i];
    }
  }
  cout<<tot<<endl;
  return 0;
}
