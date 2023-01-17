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
#define N 500005
#define M 80
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, q;
int k;
int t;
int a[N];
int sum[N];
int idx[N];
bool check(int x) {
  if (x == n+1) return true;
  int id = n+1-x;
  int num=n-x;
  if (a[id] <= m) {
    if (num-1<=0) return true;
    if (idx[id] <= num-1) {
      if (sum[num] <= m) return true;
    } else {
      if (sum[num-1]+a[id] <= m) return true;
    }
  }
  if (num+1+1>n) return false;
  if (idx[id] <= num+1) {
    if (sum[num+2]-a[id] <= m) return true;
  } else {
    if (sum[num+1] <= m) return true;
  }
  return false;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    vector<pair<int,int>> rk;
    rk.clear();
    sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      rk.push_back(make_pair(a[i], i));
    }
    sort(rk.begin(), rk.end());
    for (int i = 0; i < rk.size(); ++i) {
      idx[rk[i].second] = i+1;
      sum[i+1] = sum[i] + rk[i].first;
    }
    int ans = n+1;
    int l = 1, r = n+1;
    while(l < r) {
      int mid = (l+r)/2;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid+1;
      }
    }
    printf("%d\n", r);
  }
  return 0;
}
