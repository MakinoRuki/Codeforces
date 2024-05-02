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
#define N 200005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
int cnt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    set<int> ss;
    ss.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      ss.insert(a[i]);
    }
    vector<int> v(ss.begin(), ss.end());
    int i;
    for (i = 0; i < v.size(); ++i) {
      if (i == 0 && v[i] > 1) {
        break;
      }
      if (i > 0 && v[i]-v[i-1]>1) {
        break;
      }
    }
    if (i >= v.size()) {
      int sz=(int)v.size();
      if (sz%2) {
        puts("Alice");
      } else {
        puts("Bob");
      }
    } else {
      if (i % 2) {
        puts("Bob");
      } else {
        puts("Alice");
      }
    }
  }
  return 0;
}
