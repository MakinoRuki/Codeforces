
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
#define M 10002
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int b[N];
int c[N];
int res[20][N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n>>q;
    for (int i =1 ; i <= (1<<n); ++i) {
      scanf("%d", &a[i]);
      res[n][i] = a[i];
    }
    for (int i = n-1; i >= 0; --i) {
      for (int j = 1; j <= (1<<i); ++j) {
        int v = res[i+1][j*2-1] ^ res[i+1][j*2];
        res[i][j] = v;
      }
    }
    for (int i =1; i <= q; ++i) {
      scanf("%d%d", &b[i], &c[i]);
      int id = b[i];
      int cur = c[i];
      int ans=0;
      for (int j = n-1; j >= 0; --j) {
        int op = (id % 2) ? id+1: id-1;
        if (res[j+1][op] > cur) {
          ans += (1<<(n-j-1));
        } else if (res[j+1][op] == cur) {
          if ((id%2)==0) ans += (1<<(n-j-1));
        }
        id = id/2+1;
        cur ^= res[j+1][op];
      }
      printf("%d\n", ans);
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
