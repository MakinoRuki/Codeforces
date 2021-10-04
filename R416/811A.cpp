#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 105
#define N 20005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n, p, m;
int main() {
  int a, b;
  cin>>a>>b;
  ll x1, x2;
  for (x1 = 1; x1 * x1 <= a; ++x1) {

  }
  x1--;
  for (x2 = 1; x2*(x2+1)<=b; ++x2) {

  }
  x2--;
  if (x1 > x2) {
    puts("Valera");
  } else {
    puts("Vladik");
  }
  return 0;
}
