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
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int n1 = 0, n2 = 0;
    int n0 = 0;
    vector<int> v;
    v.clear();
    for (int i= 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i] < 0) {
        n2++;
        v.push_back(a[i]);
      } else if (a[i] > 0) {
        n1++;
        v.push_back(a[i]);
      } else {
        n0++;
      }
    }
    if (n2 > 2 || n1 > 2) {
      puts("NO");
      continue;
    }
    for (int i = 0; i < min(3, n0); ++i) {
      v.push_back(0);
    }
    bool ok=true;
    for (int i = 0; i < v.size(); ++i) {
      for (int j = i+1; j < v.size(); ++j) {
        for (int k = j+1; k < v.size(); ++k) {
          ll tmp = (ll)v[i]+(ll)v[j]+(ll)v[k];
          int x;
          for (x = 0; x < v.size(); ++x) {
            if (v[x] == tmp) {
              break;
            }
          }
          if (x >= v.size()) {
            ok=false;
            break;
          }
        }
        if (!ok) break;
      }
      if (!ok) break;
    }
    if (ok) puts("YES");
    else puts("NO");
  }
  return 0;
}
