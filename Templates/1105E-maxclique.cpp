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
#define N 42
#define M 10
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n,m,p;
int cnt[N];
bool mat[N][N];
int vis[N];
int ans;
bool dfs(int u, int pos) {
    int i, j;
    for (i = u + 1; i <= n; i++) {
        if (cnt[i] + pos <= ans) return 0;
        if (mat[u][i]) {
            for (j = 0; j < pos; j++)  if (!mat[i][vis[j]]) break;
            if (j == pos) { 
                vis[pos] = i;
                if (dfs(i, pos + 1)) return 1;
            }
        }
    }
    if (pos > ans) {
        ans = pos;
        return 1;
    }
    return 0;
}
void maxclique() {
    ans = -1;
    for (int i = n; i > 0; i--) {
        vis[0] = i;
        dfs(i, 1);
        cnt[i] = ans;
    }
}
int main() {
  cin>>n>>m;
  vector<int> v;
  v.clear();
  map<string, int> mp;
  mp.clear();
  int tot=0;
  memset(mat, true, sizeof(mat));
  for (int i = 1; i <= n; ++i) {
    string op;
    cin>>op;
    if (op == "1") {
      v.clear();
    } else {
      string s;
      cin>>s;
      int id;
      if (mp.find(s) != mp.end()) {
        id = mp[s];
      } else {
        mp[s] = ++tot;
        id = tot;
      }
      for (int j = 0; j < v.size(); ++j) {
        mat[id][v[j]] = mat[v[j]][id] = false;
      }
      v.push_back(id);
    }
  }
  n = m;
  maxclique();
  ans = max(ans, 0);
  cout<<ans<<endl;
  return 0;
}
