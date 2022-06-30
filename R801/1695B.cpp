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
#define N 55
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    if (n % 2) {
      puts("Mike");
    } else {
      int id = -1;
      for (int i = 1; i <= n; i += 2) {
        if (i == 1) {
          id = i;
        } else {
          if (min(a[i], a[i+1]) < min(a[id], a[id+1])) {
            id = i;
          }
        }
      }
      if (a[id] <= a[id+1]) {
        puts("Joe");
      } else {
        puts("Mike");
      }
    }
  }
  return 0;
}
