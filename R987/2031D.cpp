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
int n, m, k, p;
int t;
int a[N];
int bit[N];
int dp[N];
int mx[N];
int lowbit(int x) {
  return x&(-x);
}
int query(int x) {
  int res=0;
  while(x) {
    res=max(res, bit[x]);
    x -= lowbit(x);
  }
  return res;
}
void update(int x, int v) {
  while(x <= n) {
    bit[x] = max(bit[x], v);
    x += lowbit(x);
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    mx[0]=0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      mx[i]=max(mx[i-1], a[i]);
    }
    for (int i = 0; i <= n; ++i) {
      bit[i] = 0;
    }
    for (int i = n; i >= 1; --i) {
      dp[i] = mx[i];
      dp[i] = max(dp[i], query(mx[i]-1));
      update(a[i], dp[i]);
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d ", dp[i]);
    }
    cout<<endl;
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

