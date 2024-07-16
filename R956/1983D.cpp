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
#include <ctime>
#include <list>
#define N 500005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
int b[N];
int bit[N];
int lowbit(int x) {
  return x&(-x);
}
void update(int id, int v) {
  while(id <= n) {
    bit[id] += v;
    id += lowbit(id);
  }
}
int query(int id) {
  int sum=0;
  while(id) {
    sum += bit[id];
    id -= lowbit(id);
  }
  return sum;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    set<int> ss;
    ss.clear();
    for (int i =1; i <= n; ++i) {
      scanf("%d", &a[i]);
      ss.insert(a[i]);
    }
    map<int,int> idx;
    idx.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
      idx[b[i]] = i;
      if (ss.find(b[i]) != ss.end()) {
        ss.erase(b[i]);
      }
    }
    if (!ss.empty()) {
      puts("NO");
      continue;
    }
    if (n == 1) {
      puts("YES");
      continue;
    }
    for (int i = 0; i <= n; ++i) {
      bit[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
      update(i, 1);
    }
    ll sum=0LL;
    for (int i = 1; i <= n-2; ++i) {
      int id = idx[a[i]];
      if (id > 1) {
        sum += query(id-1);
      }
      update(id, -1);
    }
    if (idx[a[n-1]] < idx[a[n]]) {
      if (sum%2) puts("NO");
      else puts("YES");
    } else {
      if (sum%2) puts("YES");
      else puts("NO");
    }
  }
  return 0;
}
