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
#define M 31
#define N 1002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
vector<int> edges[N];
bool ok;
bool dfs(int u, int p) {
  bool found=false;
  int cnt=0;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v=edges[u][i];
    if (v==p) continue;
    found=true;
    if (dfs(v, u)) cnt++;
  }
  if (found && cnt<3) {
    ok=false;
  }
  return !found;
}
int main() {
  cin>>n;
  for (int i = 1; i < n; ++i) {
    int pi;
    scanf("%d", &pi);
    edges[pi].push_back(i+1);
  }
  ok=true;
  dfs(1, 0);
  if (ok) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}
