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
int x[N], y[N];
int main() {
  //ios_base::sync_with_stdio(0);
  //cin.tie(nullptr);
  // freopen("data.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  cin>>n;
  memset(x, 0, sizeof(x));
  memset(y, 0, sizeof(y));
  for (int i = 1; i <= n; ++i) {
    int w;
    cin>>w;
    x[w]++;
    y[w]++;
  }
  int add = 0;
  for (int i = 1; i <= n; ++i) {
    if (x[i]) {
      if (add) {
        add=0;
        if (x[i+1]) x[i+1]=0;
      } else {
        x[i] = 0;
        add=1;
      }
    } else {
      if (add) {
        x[i]++;
        add=0;
        if (x[i+1]) x[i+1]=0;
      }
    }
  }
  if (add) x[n]++;
  int minv = 0;
  for (int i =1 ;i<=n; ++i) {
    if (x[i]) minv++;
  }
  if (y[1]) {
    y[0]++;
    y[1]--;
  }
  add=0;
  for (int i = 1; i <= n; ++i) {
    if (y[i]) {
      if (!add) {
        if (y[i] > 1) {
          add = 1;
        }
      }
    } else {
      if (add) {
        y[i]++;
        add=0;
      } else {
        if (y[i+1]) {
          y[i+1]--;
          y[i]++;
        }
      }
    }
  }
  if (add) y[n+1]++;
  int maxv = 0;
  for (int i = 0; i <= n+1; ++i) {
    if (y[i]) maxv++;
  }
  cout<<minv<<" "<<maxv<<endl;
  return 0;
}
