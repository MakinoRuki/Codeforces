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
#define N 1000005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int mx[N], mn[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int c0=0,c1=0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i] > 0) c1++;
      else c0++;
    }
    for (int i= 1; i <= n; ++i) {
      if (c1 >= i) {
        mx[i] = i;
      } else {
        int dt=i-c1;
        mx[i] = c1-dt;
      }
      int dt = c0-i/2;
      mn[i]=0;
      if (i%2) mn[i]++;
      if (dt < 0) {
        mn[i] += abs(dt)*2;
      }
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d ", mx[i]);
    }
    cout<<endl;
    for (int i = 1; i <= n; ++i) {
      printf("%d ", mn[i]);
    }
    cout<<endl;
  }
  return 0;
}
