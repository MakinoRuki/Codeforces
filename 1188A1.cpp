// 只要没有①没连叶节点的非叶节点/②是叶节点的父亲但是只连了一个叶节点的节点就可以了
// 其他非叶节点可以是连了奇数个叶节点
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 100005
using namespace std;
int deg[N];
int n;
int main() {
  cin>>n;
  memset(deg, 0, sizeof(deg));
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin>>u>>v;
    deg[u]++;
    deg[v]++;
  }
  bool ok = true;
  for (int i = 1; i <= n; ++i) {
    if (deg[i] == 2) {
      ok = false;
      break;
    }
  }
  cout<<(ok ? "YES" : "NO")<<endl;
  return 0;
}
