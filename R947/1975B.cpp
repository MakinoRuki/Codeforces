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
int getgcd(int x, int y) {
  return y == 0 ? x : getgcd(y, x%y);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    sort(a+1, a+n+1);
    vector<int> v;
    v.clear();
    int g =0;
    for (int i = 2; i <= n; ++i) {
      if (a[i]%a[1]) {
        g = getgcd(g, a[i]);
      }
    }
    bool found=false;
    for (int i = 2; i <= n; ++i) {
      if (g % a[i]) continue;
      found=true;
      break;
    }
    if (found) {
      puts("Yes");
    } else {
      puts("No");
    }
  }
  return 0;
}
