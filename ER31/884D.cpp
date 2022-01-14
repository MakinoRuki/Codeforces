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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, q, k;
int t;
int a[N];
bool vis[N];
int main() {
  cin>>n;
  set<pair<ll,int>> ss;
  ss.clear();
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    ss.insert(make_pair((ll)x, i));
  }
  if (n == 1) {
    puts("0");
    return 0;
  }
  ll tot = 0LL;
  if (n % 2 == 0) {
    ss.insert(make_pair(0LL, 0));
  }
  while(ss.size() > 1) {
    auto p1 = *ss.begin();
    ss.erase(p1);
    auto p2 = *ss.begin();
    ss.erase(p2);
    auto p3 = *ss.begin();
    ss.erase(p3);
    ll cur = p1.first+p2.first+p3.first;
    int id = min(p1.second, min(p2.second, p3.second));
    tot += cur;
    ss.insert(make_pair(cur, id));
  }
  cout<<tot<<endl;
  return 0;
}
