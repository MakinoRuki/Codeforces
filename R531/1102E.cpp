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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, x, y;
int a[N];
int main() {
  cin>>n;
  map<int,int> ids;
  ids.clear();
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    ids[a[i]] = i;
  }
  int cnt=0;
  int i = 1;
  while(i <= n) {
    cnt++;
    int j = i;
    int e = ids[a[i]];
    while(j <= n && j <= e) {
      e = max(e, ids[a[j]]);
      j++;
    }
    i = j;
  }
  ll ans = 1LL;
  for (int i =1; i < cnt; ++i) {
    ans = ans * 2LL % mod2;
  }
  cout<<ans<<endl;
  return 0;
}
