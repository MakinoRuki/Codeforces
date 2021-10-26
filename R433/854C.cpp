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
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, h;
int k;
int c[N];
int ans[N];
int main() {
  cin>>n>>k;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &c[i]);
  }
  set<pair<int,int>> ss;
  ss.clear();
  ll tot = 0LL;
  int id = 1;
  for (int i = k+1; i <= k+n; ++i) {
    while(id <= n && id <= i) {
      ss.insert(make_pair(-c[id], id));
      id++;
    }
    auto itr = (*ss.begin());
    int x = itr.second;
  //  cout<<"i="<<i<<" "<<x<<endl;
    tot += (ll)(-itr.first) * (ll)(i-x);
    ans[x] = i;
    ss.erase(itr);
  }
  printf("%lld\n", tot);
  for (int i = 1; i <= n; ++i) {
    printf("%d", ans[i]);
    if (i < n) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
