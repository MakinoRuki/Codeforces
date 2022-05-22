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
#include <random>
#define N 200005
#define M 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 2000000000;
int n, m, k, q;
int t;
int a[N];
bool check(int c1, int c2) {
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      int x = a[i*m+j];
      int y = a[i*m+j-1];
      if (j == c1) {
        x = a[i*m+c2];
      } else if (j == c2) {
        x = a[i*m+c1];
      }
      if (j-1 == c1) {
        y = a[i*m+c2];
      } else if (j-1 ==c2) {
        y = a[i*m+c1];
      }
      if (x < y) return false;
    }
  }
  return true;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        scanf("%d", &a[i*m+j]);
      }
    }
    set<int> ss;
    ss.clear();
    for (int i = 0; i < n; ++i) {
      vector<int> b;
      b.clear();
      for (int j = 0; j < m; ++j) {
        b.push_back(a[i*m+j]);
      }
      sort(b.begin(), b.end());
      for (int j = 0; j < m; ++j) {
        if (a[i*m+j] != b[j]) {
          ss.insert(j);
        }
      }
    }
    if (ss.empty()) {
      printf("%d %d\n", 1, 1);
      continue;
    }
    if (ss.size() > 10) {
      puts("-1");
      continue;
    }
    vector<int> v(ss.begin(), ss.end());
    int c1 = -1, c2 = -1;
    for (int i = 0; i < v.size(); ++i) {
      for (int j = i; j < v.size(); ++j) {
        if (check(v[i], v[j])) {
          c1 = v[i], c2 = v[j];
          break;
        }
      }
      if (c1 >= 0) break;
    }
    if (c1 < 0) puts("-1");
    else printf("%d %d\n", c1+1, c2+1);
  }
  return 0;
}
