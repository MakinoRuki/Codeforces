
#include <iostream>
#include <sstream>
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
#include <stack>
#include <bitset>
#include <chrono>
#define N 2000005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 676767677;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
const int base=337;

int n, m, q;
ll k, w;
int t;
ll a[N];
int main() {
  cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);
    if (n == 2) {
      puts("-1");
      continue;
    }
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    a[4] = 6;
    for (int i = 5; i <= n; ++i) {
      a[i] = 2LL * a[i-1];
    }
    for (int i = 1; i <= n; ++i) {
      printf("%lld ", a[i]);
    }
    cout<<endl;
  }
  return 0;
}
