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
#define N 300005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m;
int t;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int a,b,c,d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (c <= b && a <= d) {
      printf("%d\n", max(a, c));
    } else {
      printf("%d\n", a+c);
    }
  }
  return 0;
}
