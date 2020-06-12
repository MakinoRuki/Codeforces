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
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
int a[N][N], b[N][N];
int main() {
  cin>>n>>m;
  for (int i = 1; i <= n; ++i) {
    for (int j =1; j <= m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &b[i][j]);
    }
  }
  bool ok = true;
  vector<int> ra;
  vector<int> rb;
  for (int j = 1; j <= m; ++j) {
    ra.clear();
    rb.clear();
    int ci = 1, cj = j;
    while(ci <= n && cj >= 1) {
      ra.push_back(a[ci][cj]);
      rb.push_back(b[ci][cj]);
      ci++;
      cj--;
    }
    sort(ra.begin(), ra.end());
    sort(rb.begin(), rb.end());
    int i;
    for (i = 0; i < ra.size(); ++i) {
      if (ra[i] != rb[i]) break;
    }
    if (i < ra.size()) {
      ok = false;
      break;
    }
  }
  for (int i = 1; i <= n; ++i) {
    ra.clear();
    rb.clear();
    int ci = i, cj = m;
    while(ci <= n && cj >= 1) {
      ra.push_back(a[ci][cj]);
      rb.push_back(b[ci][cj]);
      ci++;
      cj--;
    }
    sort(ra.begin(), ra.end());
    sort(rb.begin(), rb.end());
    int j;
    for (j = 0; j < ra.size(); ++j) {
      if (ra[j] != rb[j]) break;
    }
    if (j < ra.size()) {
      ok = false;
      break;
    }
  }
  if (ok) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
