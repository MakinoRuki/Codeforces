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
#define M 202
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x == 0 && y == 0) {
      puts("0");
    } else {
      int d = x * x + y * y;
      int qr = (int)sqrt(d);
      if (qr * qr == d) {
        puts("1");
      } else {
        puts("2");
      }
    }
  }
  return 0;
}
