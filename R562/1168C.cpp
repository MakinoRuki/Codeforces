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
#define N 300005
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, q;
int a[N];
int b[N][20];
int c[N][20];
int main() {
  cin>>n>>q;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n+1; ++i) {
    for (int j = 0; j < 20; ++j) {
      b[i][j] = n+1;
      c[i][j] = n+1;
    }
  }
  for (int i = n; i >= 1; --i) {
    for (int j = 0; j < 20; ++j) {
      if ((1<<j)&a[i]) {
        b[i][j] = i;
      } else {
        b[i][j] = b[i+1][j];
      }
      if ((1<<j)&a[i]) {
        c[i][j] = i;
      } else {
        for (int k = 0; k < 20; ++k) {
          if (((1<<k)&a[i]) && (b[i+1][k]<=n)) {
            c[i][j] = min(c[i][j], c[b[i+1][k]][j]);
          }
        }
      }
    }
  }
  // for (int i = 1; i <= n; ++i) {
  //   cout<<i<<endl;
  //   cout<<b[i][0]<<" "<<b[i][1]<<endl;
  //   cout<<c[i][0]<<" "<<c[i][1]<<endl;
  // }
  for (int i = 1; i <= q; ++i) {
    int x,y;
    scanf("%d%d", &x, &y);
    bool found=false;
    for (int j = 0; j < 20; ++j) {
      if (((1<<j)&a[y]) && c[x][j]<=y) {
        found=true;
        break;
      }
    }
    if (found) cout<<"Shi"<<endl;
    else cout<<"Fou"<<endl;
  }
  return 0;
}
