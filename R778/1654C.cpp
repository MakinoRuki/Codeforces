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
#define M 10000002
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int cnt[26];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    map<ll,int> cnt;
    map<ll,int> mp;
    cnt.clear();
    mp.clear();
    ll tot = 0LL;
    for (int i =1; i <= n; ++i) {
      scanf("%d", &a[i]);
      tot += (ll)a[i];
      cnt[a[i]]++;
    }
    mp[tot]++;
    bool ok = true;
    while(cnt.size() > 0) {
      auto cur = (*mp.begin());
      mp[cur.first]--;
      if (mp[cur.first] == 0) {
        mp.erase(cur.first);
      }
      if (cur.first < (*cnt.begin()).first) {
        ok = false;
        break;
      }
      if (cnt.find(cur.first) != cnt.end()) {
        cnt[cur.first]--;
        if (cnt[cur.first] == 0) {
          cnt.erase(cur.first);
        }
      } else {
        if (cur.first == 1) {
          ok=false;
          break;
        }
        ll v = cur.first/2;
        ll v2 = cur.first-v;
        mp[v]++;
        mp[v2]++;
      }
    }
    if (ok && mp.empty() && cnt.empty()) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}
