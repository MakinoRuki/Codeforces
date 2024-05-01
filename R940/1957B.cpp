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
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    int mb = 0;
    while((1<<mb) <= k) {
      mb++;
    }
    mb--;
    if (__builtin_popcount(k) > __builtin_popcount((1<<mb)-1) || (n<=1)) {
      printf("%d", k);
      for (int i = 1; i < n; ++i) {
        printf(" 0");
      }
      cout<<endl;
    } else {
      printf("%d %d", (1<<mb)-1, 1+(k-(1<<mb)));
      for (int i = 1; i <= n-2; ++i) {
        printf(" 0");
      }
      cout<<endl;
    }
  }
  return 0;
}
