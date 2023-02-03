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
#define N 100005
#define M 520
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int d;
string a,b;
bool vis[30];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    cin>>a>>b;
    set<int> ss;
    ss.clear();
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i]) {
        ss.insert(a[i]-'a');
      }
    }
    for (int i = 0; i < 26; ++i) {
      vis[i] = false;
    }
    vector<int> v(ss.begin(), ss.end());
    int sz = (int)v.size();
    ll ans = 0LL;
    for (int i = 0; i < (1<<sz); ++i) {
      int num=0;
      for (int j = 0; j < sz; ++j) {
        if ((1<<j) & i) {
          num++;
          vis[v[j]] = true;
        } else {
          vis[v[j]] = false;
        }
      }
      if (num > k) continue;
      ll cnt = 0LL;
      ll sum = 0LL;
      for (int j = 0; j < n; ++j) {
        if (a[j] == b[j] || vis[a[j]-'a']) {
          cnt++;
        } else {
          sum += cnt * (cnt+1)/2;
          cnt = 0LL;
        }
      }
      sum += cnt*(cnt+1)/2;
      ans = max(ans, sum);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
