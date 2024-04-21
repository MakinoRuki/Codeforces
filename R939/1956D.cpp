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
#define N 1000005
#define M 635
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
int a[M];
vector<pair<int,int>> v;
void dfs(int l, int r) {
  if (r-l+1<=1) return;
  if (r-l+1==2) {
    v.push_back(make_pair(l, l));
    return;
  }
  dfs(l, r-1);
  v.push_back(make_pair(l, r-1));
  v.push_back(make_pair(l+1, r-1));
  dfs(l+1, r);
}
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  ll ans=-1;
  int st=-1;
  for (int i = 0; i < (1<<n); ++i) {
    ll tmp=0LL;
    int cnt=0;
    for (int j = 1; j <= n; ++j) {
      if ((1<<(j-1))&i) {
        cnt++;
      } else {
        tmp += (ll)cnt*(ll)cnt;
        cnt=0;
        tmp += a[j];
      }
    }
    tmp += (ll)cnt*(ll)cnt;
    if (tmp > ans) {
      ans = tmp;
      st = i;
    }
  }
  v.clear();
  int cnt=0;
  for (int i = 1; i <= n; ++i) {
    if ((1<<(i-1))&st) {
      cnt++;
    } else {
      if (cnt>0) {
        int num=0;
        for (int j = i-cnt; j <= i-1; ++j) {
          if (a[j] != 0) num++;
        }
        if (num > 0) {
          v.push_back(make_pair(i-cnt, i-1));
          if (num < cnt) {
            v.push_back(make_pair(i-cnt, i-1));
          }
        }
        dfs(i-cnt, i-1);
        v.push_back(make_pair(i-cnt, i-1));
      }
      cnt=0;
    }
  }
  if (cnt) {
    int num=0;
    for (int j = n+1-cnt; j <= n; ++j) {
      if (a[j] != 0) num++;
    }
    if (num > 0) {
      v.push_back(make_pair(n+1-cnt, n));
      if (num < cnt) {
        v.push_back(make_pair(n+1-cnt, n));
      }
    }
    dfs(n+1-cnt, n);
    v.push_back(make_pair(n+1-cnt, n));
  }
  printf("%lld %d\n", ans, (int)v.size());
  for (int i = 0; i < v.size(); ++i) {
    printf("%d %d\n", v[i].first, v[i].second);
  }
  return 0;
}
