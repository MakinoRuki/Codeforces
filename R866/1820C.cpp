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
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    map<int, int> mp;
    mp.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      mp[a[i]]++;
    }
    int mex = 0;
    for (mex = 0; mex <= n; ++mex) {
      if (mp.find(mex) == mp.end()) {
        break;
      }
    }
    int l=-1,r=-1;
    for (int i = 1; i <= n; ++i) {
      if (a[i] == mex+1) {
        if (l < 0) l = i;
        else r = i;
      }
    }
    bool ok=false;
    if (l < 0) {
      for (int i = 0; i < mex; ++i) {
        if (mp[i] > 1) {
          ok=true;
          break;
        }
      }
      if (n > mex) ok=true;
    } else {
      mp.clear();
      for (int i = 1; i < l; ++i) {
        mp[a[i]]++;
      }
      for (int i = r+1; i <= n; ++i) {
        mp[a[i]]++;
      }
      int i;
      for (i = 0; i < mex; ++i) {
        if (mp.find(i) == mp.end()) {
          break;
        }
      }
      if (i >= mex) {
        ok=true;
      }
    }
    if (ok) puts("Yes");
    else puts("No");
  }
  return 0;
}
