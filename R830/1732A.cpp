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
#include <list>
#define N 1000005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int getgcd(int x, int y) {
    return y == 0 ? x : getgcd(y, x%y);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int g=0;
    int g1=0,g2=0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        g = getgcd(g, a[i]);
        if (i != n-1) {
            g2 = getgcd(g2, a[i]);
        }
        if (i != n) {
            g1 = getgcd(g1, a[i]);
        }
    }
    g1 = getgcd(g1, getgcd(a[n], n));
    g2 = getgcd(g2, getgcd(a[n-1], n-1));
    if (g == 1) {
        puts("0");
        continue;
    }
    if (g1 == 1) {
        puts("1");
        continue;
    }
    if (g2 == 1) {
        puts("2");
        continue;
    }
    puts("3");
  }
  return 0;
}
