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
#define M 500005
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q, p;
int l, r;
int t;
string s;
vector<int> edges[N];
int dis[N];
int main() {
  cin>>n>>k;
  if (k == 2) {
    printf("%d\n", n-1);
    for (int i = 1; i < n; ++i) {
      printf("%d %d\n", i, i+1);
    }
  } else {
    for (int i = 2; i <= k+1; ++i) {
      edges[i].push_back(1);
      edges[1].push_back(i);
      dis[i] = 1;
    }
    for (int i = k+2; i <= n; ++i) {
      edges[i].push_back(i-k);
      edges[i-k].push_back(i);
      dis[i] = dis[i-k]+1;
    }
    int mx1=0,mx2=0;
    for (int i = 1; i <= k; ++i) {
      if (dis[n-i+1] > mx1) {
        mx1 = dis[n-i+1];
      } else if (dis[n-i+1] > mx2) {
        mx2 = dis[n-i+1];
      }
    }
    printf("%d\n", mx1+mx2);
    vector<pair<int,int>> ans;
    ans.clear();
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < edges[i].size(); ++j) {
        if (i < edges[i][j]) {
          ans.push_back(make_pair(i, edges[i][j]));
        }
      }
    }
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d %d\n", ans[i].first, ans[i].second);
    }
  }
  return 0;
}
