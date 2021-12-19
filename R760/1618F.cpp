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
#define N 200005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k;
int t;
string s;
ll a[N];
ll ans[N];
bool check(vector<int>& ds, int l, int r) {
  for (int i = 0; i <= l; ++i) {
    if (ds[i] != 1) return false;
  }
  for (int i = r; i < ds.size(); ++i) {
    if (ds[i] != 1) return false;
  }
  return true;
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d", &n);
  // }
  ll x, y;
  scanf("%lld%lld", &x, &y);
  vector<int> dx, dy;
  dx.clear();
  dy.clear();
  while(x) {
    dx.push_back(x%2);
    x/=2;
  }
  reverse(dx.begin(), dx.end());
  while(y) {
    dy.push_back(y%2);
    y/=2;
  }
  reverse(dy.begin(), dy.end());
  if (dx.size() > dy.size()) {
    int i;
    for (i = 0; i < dy.size(); ++i) {
      if (dx[i] != dy[i]) {
        break;
      }
    }
    if (i >= dy.size()) {
      puts("YES");
    } else {
      for (i = 0; i < dy.size(); ++i) {
        if (dx[dy.size()-1-i] != dy[i]) {
          break;
        }
      }
      if (i >= dy.size()) {
        puts("YES");
      } else {
        puts("NO");
      }
    }
  } else {
    bool found=false;
    int id = dx.size()-1;
    while(id >= 0 && dx[id] == 0) {
      id--;
    }
    id++;
    for (int i = 0; i + dx.size() <= dy.size(); ++i) {
      int j;
      for (j = 0; j < dx.size(); ++j) {
        if (dx[j] != dy[i+j]) {
          break;
        }
      }
      if (j >= dx.size() && check(dy, i-1, i+dx.size())) {
        found=true;
        break;
      }
      for (j = 0; j< dx.size(); ++j) {
        if (dx[dx.size()-1-j] != dy[i+j]) {
          break;
        }
      }
      if (j >= dx.size() && check(dy, i-1, i + dx.size())) {
        found=true;
        break;
      }
    }
    for (int i = 0; i + id <= dy.size(); ++i) {
      int j;
      for (j = 0; j < id; ++j) {
        if (dx[j] != dy[i+j]) {
          break;
        }
      }
      if (j >= id && check(dy, i-1, i+id)) {
        found=true;
        break;
      }
      for (j = 0; j< id; ++j) {
        if (dx[id-1-j] != dy[i+j]) {
          break;
        }
      }
      if (j >= id && check(dy, i-1, i + id)) {
        found=true;
        break;
      }
    }
    if (found)puts("YES");
    else puts("NO");
  }
  return 0;
}
