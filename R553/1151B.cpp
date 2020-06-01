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
#define N 502
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int n, m;
int a[N][N];
int main() {
  cin>>n>>m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int b = 0; b <= 10; ++b) {
    vector<vector<int>> ans;
    ans.clear();
    for (int i = 0; i < n; ++i) {
      ans.push_back({-1, -1});
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if ((1<<b)&a[i][j]) {
          if (ans[i][1] < 0) ans[i][1] = j+1;
        } else {
          if (ans[i][0] < 0) ans[i][0] = j+1;
        }
      }
    }
    int tot=0;
    for (int i = 0; i < n; ++i) {
      if (ans[i][0] < 0 && ans[i][1] >= 0) tot++;
    }
    if (tot % 2) {
      cout<<"TAK"<<endl;
      for (int i = 0; i < n; ++i) {
        if (ans[i][0] < 0) printf("%d", ans[i][1]);
        else printf("%d", ans[i][0]);
        if (i < n-1) cout<<" ";
        else cout<<endl;
      }
      return 0;
    } else {
      if (tot == n) continue;
      int i;
      for (i = 0; i < n; ++i) {
        if (ans[i][0]>=0 && ans[i][1]>=0) break;
      }
      if (i >= n) continue;
      cout<<"TAK"<<endl;
      for (int i2 = 0; i2 < n; ++i2) {
        if (ans[i2][0] < 0) printf("%d", ans[i2][1]);
        else {
          if (i2 == i) printf("%d", ans[i2][1]);
          else printf("%d", ans[i2][0]);
        }
        if (i2 < n-1) cout<<" ";
        else cout<<endl;
      }
      return 0;
    }
  }
  cout<<"NIE"<<endl;
  return 0;
}
