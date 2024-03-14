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
#define N 300005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
ll a[N];
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
      int mex=0;
      for (int i = 0; i <= n; ++i) {
          if (ss.find(i) == ss.end()) {
              mex = i;
              break;
          }
      }
      ss.clear();
      int i;
      for (i = 1; i < n; ++i) {
          if (a[i] < mex) {
              ss.insert(a[i]);
              
          }
          if (ss.size()>=mex) {
              break;
          }
      }
      if (i >= n) {
          puts("-1");
          continue;
      }
      ss.clear();
      for (int j = n; j > i; --j) {
          if (a[j] < mex) {
              ss.insert(a[j]);
          }
      }
      if (ss.size() >= mex) {
          puts("2");
          printf("%d %d\n", 1, i);
          printf("%d %d\n", i+1, n);
      } else {
          puts("-1");
      }
  }
  return 0;
}
