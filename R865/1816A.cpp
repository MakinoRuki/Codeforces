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
#define N 300005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a,b;
int getgcd(int x, int y) {
    return y == 0 ? x : getgcd(y, x%y);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &a, &b);
    if (getgcd(a,b) == 1) {
        puts("1");
        printf("%d %d\n", a, b);
    } else {
        puts("2");
        printf("%d %d\n", a-1, 1);
        printf("%d %d\n", a, b);
    }
  }
  return 0;
}

