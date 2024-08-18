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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    map<int, int> cnt;
    cnt.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      cnt[a[i]]++;
    }
    bool found=false;
    for (auto itr : cnt) {
      if (itr.second % 2) {
        found=true;
        break;
      }
    }
    if (found) puts("YES");
    else puts("NO");
  }
  return 0;
}
