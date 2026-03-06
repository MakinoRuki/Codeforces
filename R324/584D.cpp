#include <iostream>
#include <sstream>
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
#define N 1000005
#define M 110
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const ll mod3 = 1000003;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
bool check(int x) {
  if (x <= 1) return false;
  for (ll i = 2; i * i <= x; ++i) {
    if ((x % i)==0) return false;
  }
  return true;
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d", &n);
  // }
  cin>>n;
  if (check(n)) {
    puts("1");
    printf("%d\n", n);
  } else {
    if (check(n-3)) {
      puts("2");
      printf("%d %d\n", 3, n-3);
    } else {
      for (int i = 2; i <= n-3; ++i) {
        if (!check(i)) continue;
        if (!check(n-3-i)) continue;
        puts("3");
        printf("3 %d %d\n", i, n-3-i);
        return 0;
      }
    }
  }
  return 0;
}
 
