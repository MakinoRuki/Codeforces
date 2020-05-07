#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
vector<int> edges[N];
int deg[N];
int main() {
  cin>>n;
  memset(deg, 0, sizeof(deg));
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
  bool ok = true;
  for (int i = 1; i <= n; ++i) {
    if (deg[i] == 2) ok = false;
  }
  if (ok) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
