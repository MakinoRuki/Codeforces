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
#define N 1000005
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int p[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int a,b,c;
    scanf("%d%d%d", &a, &b, &c);
    if (c % 2) {
      if (a >= b) {
        puts("First");
      } else {
        puts("Second");
      }
    } else {
      if (a > b) puts("First");
      else puts("Second");
    }
  }
  return 0;
}
