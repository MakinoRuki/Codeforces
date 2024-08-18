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
    int x,y;
    scanf("%d%d%d", &n, &x, &y);
    if ((y-1)%2) {
      for (int i = 1; i < y; ++i) {
        if (i%2) a[i] = -1;
        else a[i]=1;
      }
    } else {
      for (int i = 1; i < y; ++i) {
        if (i%2) a[i]=1;
        else a[i]=-1;
      }
    }
    for (int i = y; i <= x; ++i) {
      a[i] = 1;
    }
    for (int i = x+1; i <= n; ++i) {
      if ((i-x)%2) {
        a[i] = -1;
      } else {
        a[i] = 1;
      }
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d ", a[i]);
    }
    cout<<endl;
  }
  return 0;
}
