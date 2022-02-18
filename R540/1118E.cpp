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
int cnt[N], cur[N];
int main() {
  cin>>n>>k;
  ll tot = (ll)k*(ll)(k-1);
  if (tot < n) {
    puts("NO");
    return 0;
  }
  for (int i = 1; i <= k; ++i) {
    cur[i] = (i)%k+1;
    cnt[i] = 0;
  }
  int id = 1;
  puts("YES");
  for (int i = 1; i <= n; ++i) {
    while(cnt[id] >= k-1) {
      id = (id)%k+1;
    }
    printf("%d %d\n", id, cur[id]);
    int nxt = cur[id];
    cur[id] = (cur[id])%k+1;
    cnt[id]++;
    id = nxt;
  }
  
  return 0;
}
