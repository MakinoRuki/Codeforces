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
#define N 102
#define M 2505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    if (n % 3 == 0) {
      printf("%d\n", n/3);
    } else if (n % 3 == 2) {
      printf("%d\n", n/3+1);
    } else {
      if (n == 1) {
        puts("2");
      } else {
        int dt = n/3;
        printf("%d\n", dt-1+2);
      }
    }
  }
  return 0;
}
