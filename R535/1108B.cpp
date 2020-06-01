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
#define N 200
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
int d[N];
bool vis[N];
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &d[i]);
  }
  sort(d+1, d+n+1);
  int x = d[n];
  memset(vis, false, sizeof(vis));
  for (int i = 1; i * i <= x; ++i) {
    if (x%i==0) {
      for (int j = 1; j <= n; ++j) {
        if (d[j] == i && !vis[j]) {
          vis[j] = true;
          break;
        }
      }
      if (x/i != i) {
        for (int j = 1; j <= n; ++j) {
          if (d[j] == x/i && !vis[j]) {
            vis[j] = true;
            break;
          }
        }
      }
    }
  }
  vector<int> ys;
  ys.clear();
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) ys.push_back(d[i]);
  }
  sort(ys.begin(), ys.end());
  int y = ys.back();
  cout<<x<<" "<<y<<endl;
  return 0;
}
