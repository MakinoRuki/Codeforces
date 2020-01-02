#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <deque>
#define N 200005
using namespace std;
typedef long long ll;
int n;
int a[N];
int main() {
  //ios_base::sync_with_stdio(0);
  //cin.tie(nullptr);
  // freopen("data.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  cin>>n;
  for (int i = 0; i < n-1; ++i) {
    cin>>a[i];
  }
  bool vis[N];
  memset(vis, false, sizeof(vis));
  cout<<a[0]<<endl;
  int maxv = n;
  // 要么取相邻点连边，要么取未使用的最大点连边。
  for (int i = 0; i < n-1;++i) {
    vis[a[i]] = true;
    if (i +1 < n-1 && !vis[a[i+1]]) {
      cout<<a[i]<<" "<<a[i+1]<<endl;
      vis[a[i+1]]=true;
    } else {
      while(vis[maxv]) maxv--;
      cout<<a[i]<<" "<<maxv<<endl;
      vis[maxv] = true;
    }
  }
  return 0;
}
