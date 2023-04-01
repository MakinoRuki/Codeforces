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
#define N 2000
#define M 22
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    if (n % 2 == 0) {
      puts("No");
    } else {
      puts("Yes");
      int j = 1;
      for (int i = 2*n; i > n; --i) {
        printf("%d %d\n", i, j);
        j += 2;
        if (j > n) j = 2;
      }
    }
  }
  return 0;
}
