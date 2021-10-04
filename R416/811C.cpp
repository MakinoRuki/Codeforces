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
#define M 105
#define N 5002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n, m;
int a[N];
int idx1[N], idx2[N];
int bn[N], ed[N];
int val[N];
int dp[N];
bool vis[N];
int main() {
  cin>>n;
  memset(idx1, -1, sizeof(idx1));
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (idx1[a[i]] < 0) {
      idx1[a[i]] = i;
    }
    idx2[a[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    int cur = i;
    int b = idx1[a[i]], e = idx2[a[i]];
    int l = i, r = i;
    while(l >= b || r <= e) {
      while(l >= b) {
        b = min(b, idx1[a[l]]);
        e = max(e, idx2[a[l]]);
        l--;
      }
      while(r <= e) {
        b = min(b, idx1[a[r]]);
        e = max(e, idx2[a[r]]);
        r++;
      }
    }
    bn[i] = b;
    ed[i] = e;
    val[i] = 0;
    for (int j = 1; j <= n; ++j) {
      vis[a[j]] = false;
    }
    for (int j = bn[i]; j <= ed[i]; ++j) {
      if (!vis[a[j]]) {
        val[i] ^= a[j];
        vis[a[j]] = true;
      }
    }
  }
  // int cur = 1;
  // vector<pair<int,int>> sgs;
  // sgs.clear();
  // while(cur <= n) {
  //   int i = cur;
  //   int e = cur;
  //   while(i <= n) {
  //     if (i > e) break;
  //     e = max(e, idx[a[i]]);
  //     i++;
  //   }
  //   sgs.push_back(make_pair(cur, e));
  //   cur = i;
  // }
  // xors.clear();
  // for (int i = 0; i < sgs.size(); ++i) {
  //   set<int> ss;
  //   ss.clear();
  //   for (int j = sgs[i].first; j <= sgs[i].second; ++j) {
  //     bn[j] = sgs[i].first;
  //     ed[j] = sgs[i].second;
  //     ss.insert(a[j]);
  //   }
  //   int sum=0;
  //   for (auto itr : ss) {
  //     sum ^= itr;
  //   }
  //   for (int j = sgs[i].first; j <= sgs[i].second; ++j) {
  //     val[j] = sum;
  //   }
  //   xors.push_back(sum);
  // }
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  int ans=0;
  for (int i = 0; i < n; ++i) {
    if (dp[i] >= 0) {
      for (int j = i + 1; j <= n; ++j) {
        if (bn[j] >= i+1) {
          dp[ed[j]] = max(dp[ed[j]], dp[i] + val[j]);
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
  //  cout<<i<<" "<<dp[i]<<endl;
    ans = max(ans, dp[i]);
  }
  cout<<ans<<endl;
  return 0;
}
