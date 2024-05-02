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
#include <random>
#include <ctime>
#include <list>
#define N 200005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
int cnt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    int tot=0;
    set<pair<int,int>> ss;
    ss.clear();
    int mx=0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      cnt[a[i]]++;
      mx=max(mx, a[i]);
    }
    for (int i = 1; i <= mx; ++i) {
      tot += cnt[i]/k*(k-1);
      if (cnt[i]%k) {
        ss.insert(make_pair(k-cnt[i]%k, i));
      }
    }
    while(!ss.empty()) {
      auto itr = *ss.begin();
      if (itr.first <= tot) {
        tot -= itr.first;
        ss.erase(itr);
        tot += k-1;
      } else {
        break;
      }
    }
    tot = min(tot, k-1);
    while(!ss.empty()) {
      tot += k-(*ss.begin()).first;
      ss.erase(ss.begin());
    }
    printf("%d\n", tot);
    for (int i = 1; i <= n; ++i) {
      cnt[a[i]]--;
    }
  }
  return 0;
}
