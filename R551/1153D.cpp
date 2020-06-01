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
//#include <priority_queue>
#define N 300005
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
int fn[N];
int sons[N];
vector<int> edges[N];
void dfs(int u) {
  if (edges[u].empty()) sons[u] = 1;
  else {
    for (int i = 0; i < edges[u].size(); ++i) {
      int v = edges[u][i];
      dfs(v);
      sons[u] += sons[v];
    }
  }
}
int dfs2(int u) {
  int maxv = 0;
  int sum = 0;
  if (edges[u].empty()) {
    return 1;
  }
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    int res = dfs2(v);
    sum += res-1;
    maxv = max(maxv, sons[u] - (sons[v]-res));
  }
  if (fn[u] == 0) {
    return sum+1;
  } else {
    return maxv;
  }
}
int main() {
  cin>>n;
  for (int i =1 ; i <= n; ++i) {
    scanf("%d", &fn[i]);
  }
  for (int i = 2; i <= n; ++i) {
    int f;
    scanf("%d", &f);
    edges[f].push_back(i);
  }
  dfs(1);
  cout<<dfs2(1)<<endl;
  return 0;
}
