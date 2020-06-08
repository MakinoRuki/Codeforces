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
#define N 500005
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
vector<int> edges[N];
int t[N];
vector<int> pts[N];
int t2[N];
int main() {
  cin>>n>>m;
  for (int i = 1; i <= m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &t[i]);
    pts[t[i]].push_back(i);
  }
  vector<int> ans;
  ans.clear();
  bool ok = true;
  memset(t2, -1, sizeof(t2));
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < pts[i].size(); ++j) {
      int x = pts[i][j];
      set<int> ss;
      ss.clear();
      for (int k = 0; k < edges[x].size(); ++k) {
        int v = edges[x][k];
        if (t2[v] >= 0 && t2[v] < i) {
          ss.insert(t2[v]);
        } else if (t2[v] == i) {
          ok = false;
          break;
        }
      }
      if (!ok) {
        break;
      }
      if (ss.size() < i-1) {
        ok = false;
        break;
      }
      t2[x] = i;
      ans.push_back(x);
    }
  }
  if (!ok) {
    cout<<-1<<endl;
  } else {
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d", ans[i]);
      if (i < ans.size()-1) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
