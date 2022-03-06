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
#define N 1000005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int pr[N];
vector<pair<int,int>> ps[N];
bool vis[21 * N];
ll sum[22];
int getgcd(int x, int y) {
  return y == 0 ? x : getgcd(y, x % y);
}
bool check(int x) {
  int g = ps[x][0].second;
  for (int i = 1; i < ps[x].size(); ++i) {
    g = getgcd(g, ps[x][i].second);
  }
  return g == 1;
}
int main() {
  cin>>n>>m;
  for (int i = 1; i <= n; ++i) {
    pr[i] = i;
  }
  for (int i = 2; i <= n; ++i) {
    if (pr[i] == i) {
      for (int j = 2 * i; j <= n; j += i) {
        pr[j] = min(pr[j], i);
      }
    }
  }
  for (int i = 2; i <= n; ++i) {
    ps[i].clear();
    if (pr[i] == i) {
      ps[i].push_back(make_pair(i, 1));
    } else {
      int x = i;
      int cnt = 0;
      while(x % pr[i] == 0) {
        cnt++;
        x/=pr[i];
      }
      ps[i] = ps[x];
      ps[i].push_back(make_pair(pr[i], cnt));
    }
  }
  for (int i = 0; i <= 20 * m; ++i) {
    vis[i] = false;
  }
  memset(sum, 0LL, sizeof(sum));
  for (int i = 1; i <= 20; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (!vis[i*j]) {
        sum[i]++;
        vis[i*j] = true;
      }
    }
    sum[i] += sum[i-1];
  }
  ll tot = 1LL;
  for (int i = 2; i <= n; ++i) {
    if (check(i)) {
      int cnt=0;
      ll tmp = i;
      while(tmp <= n) {
        cnt++;
        if (tmp <= n/i) {
          tmp *= (ll)i;
        } else {
          break;
        }
      }
      tot += sum[cnt];
    }
  }
  printf("%lld\n", tot);
  return 0;
}
