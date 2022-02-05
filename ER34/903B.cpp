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
#define M 500005
#define N 1005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
int main() {
  int h1,a1,c1;
  int h2,a2;
  cin>>h1>>a1>>c1;
  cin>>h2>>a2;
  int ax = -1, ay = -1;
  for (int i = 0; i <= 100000; ++i) {
    int x = (h1+i*c1+a2-1)/a2;
    int y = (h2+a1-1)/a1;
    if (x >= y+i) {
      if (ax < 0 || i + y < ax+ay) {
        ax = i;
        ay = y;
      }
    }
  }
  printf("%d\n", ax+ay);
  for (int i = 1; i <= ax; ++i) {
    puts("HEAL");
  }
  for (int i = 1; i <= ay; ++i) {
    puts("STRIKE");
  }
  return 0;
}
