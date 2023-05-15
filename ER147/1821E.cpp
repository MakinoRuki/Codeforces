#include <iostream>
#include <cstdio>
#include <stdio.h>
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
#include <cstring>
#define N 200005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q, p;
int t;
vector<int> v;
vector<int> edges[N];
int num;
int mp[N];
int dfs(int rt) {
  if (edges[rt].empty()) {
    return 1;
  }
  int tot=0;
  for (int i = 0; i < edges[rt].size(); ++i) {
    tot += dfs(edges[rt][i]);
  }
  v.push_back(tot);
  return tot+1;
}
int main() {
  cin>>t;
  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &k);
    string s;
    cin>>s;
    n = (int)s.size();
    string tmp = "";
    int cnt=0;
    v.clear();
    num=0;
    int rt = 0;
    vector<int> stk;
    stk.clear();
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
    }
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') {
        cnt++;
        mp[i] = ++num;
        if (stk.empty()) rt = num;
        stk.push_back(i);
      } else {
        cnt--;
        int cur = stk.back();
        stk.pop_back();
        if (cnt == 0) {
          dfs(rt);
        } else {
          int pre =stk.back();
          edges[mp[pre]].push_back(mp[cur]);
        }
      }
    }
    sort(v.begin(), v.end());
    ll tot = 0LL;
    for (int i = 0; i < v.size(); ++i) {
      tot += v[i];
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < min((int)v.size(), k); ++i) {
      tot -= v[i];
    }
    printf("%lld\n", tot);
  }
  return 0;
}
