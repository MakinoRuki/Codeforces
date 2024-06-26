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
#define M 5005
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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int mn=inf;
    int id=0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    bool found=false;
    for (int i = 1; i <= n; ++i) {
      vector<int> v;
      v.clear();
      for (int j = i; j <= n; ++j) {
        v.push_back(a[j]);
      }
      for (int j = 1; j < i; ++j) {
        v.push_back(a[j]);
      }
      int j;
      for (j = 1; j < v.size(); ++j) {
        if (v[j] < v[j-1]) {
          break;
        }
      }
      if (j < v.size()) {
        continue;
      }
      found=true;
      break;
    }
    if (found) puts("Yes");
    else puts("No");
  }
  return 0;
}
