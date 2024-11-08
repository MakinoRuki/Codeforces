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
#include <stack>
#include <bitset>
#include <chrono>
#define N 500005
#define M 405
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, p, q;
int t;
int a[N];
int bit[N];
int ans[N];
int lowbit(int x) {
  return x & (-x);
}
int query(int x) {
  int tot=0;
  while(x) {
    tot += bit[x];
    x -= lowbit(x);
  }
  return tot;
}
void update(int x, int v) {
  while(x <= n) {
    bit[x] += v;
    x += lowbit(x);
  }
}
bool check(int id, int x) {
  int res = query(x);
  if (res < (ll)a[id] * (ll)x) return true;
  return false;
}
int main() {
  cin>>n>>q;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  memset(bit, 0, sizeof(bit));
  for (int i = 1; i <= n; ++i) {
    int l = 1, r = n;
    while(l < r) {
      int mid=(l+r)/2;
      if (check(i, mid)) {
        r = mid;
      } else {
        l = mid+1;
      }
    }
    ans[i] = r;
    update(r, 1);
  }
  while(q-->0) {
    int id, x;
    scanf("%d%d", &id, &x);
    if (x >= ans[id]) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
