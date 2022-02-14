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
#define M 202
#define N 30
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
ll a[N][N];
int main() {
  cin>>n;
  memset(a, 0LL, sizeof(a));
  for (int i = 0; i < n; ++i) {
    int x = 0, y = i;
    int f = 1;
    while(x >=0 && x < n && y >=0 && y < n) {
      if (f) a[x][y] = 1LL<<i;
      x++, y--;
      f = !f;
    }
  }
  for (int i = 1; i < n; ++i) {
    int x = i, y = n-1;
    int f = 1;
    while(x >=0 && x < n && y >= 0 && y < n) {
      if (f) a[x][y] = 1LL<<(n-1+i);
      x++, y--;
      f = !f;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (j < n-1) printf("%lld ", a[i][j]);
      else printf("%lld\n", a[i][j]);
      fflush(stdout);
    }
  }
  cin>>q;
  while(q-->0) {
    ll k;
    scanf("%lld", &k);
    vector<pair<int,int>> ans;
    ans.push_back(make_pair(1,1));
    int x = 0, y = 0;
    for (int i = 1; i <= 2*n-2; ++i) {
      if ((1LL<<i) & k) {
        if (x+1<n && a[x+1][y] == (1LL<<i)) {
          x++;
        } else if (y+1<n && a[x][y+1] == (1LL<<i)) {
          y++;
        }
      } else {
        if (x+1<n && !a[x+1][y]) {
          x++;
        } else if (y+1<n && !a[x][y+1]) {
          y++;
        }
      }
      ans.push_back(make_pair(x+1, y+1));
    }
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d %d\n" ,ans[i].first, ans[i].second);
      fflush(stdout);
    }
  }
  return 0;
}
