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
#define M 15
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int b[N];
void dfs(int x, int y, ll& dt) {
  if (x == 0) {
    return;
  }
  if (y == 0) {
    dt++;
    dfs(y, abs(x-y), dt);
    return;
  }
  if (x < 2*y) {
    dt++;
    dfs(y, abs(x-y), dt);
  } else {
    int r = x % (2*y);
    dt += x/(2*y)*3;
    dfs(r, y, dt);
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
    }
    set<int> ss;
    ss.clear();
    for (int i =1; i <= n; ++i) {
      if (!a[i] && !b[i]) {
        continue;
      }
      ll dt=0LL;
      dfs(a[i], b[i], dt);
   //   cout<<"dt="<<dt<<endl;
      ss.insert(dt%3);
    }
    if ((int)ss.size() > 1) {
      puts("NO");
    } else {
      puts("YES");
    }
  }
  return 0;
}
