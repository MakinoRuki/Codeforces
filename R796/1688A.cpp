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
#define N 1005
#define M 1005
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
    int x;
    scanf("%d", &x);
    int pw = 0;
    while(!((1<<pw) & x)) {
      pw++;
    }
    if ((1<<pw) < x) {
      printf("%d\n", (1<<pw));
    } else {
      if (x > 1) {
        printf("%d\n", (x|1));
      } else {
        printf("%d\n", 3);
      }
    }
  }
  return 0;
}
