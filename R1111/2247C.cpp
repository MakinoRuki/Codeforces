
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
int k, w;
int t;
int a[N];
int b[N];
int main() {
  cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
    }
    int cnt=0;
    int n0=0,n1=0;
    int c0=0,c1=0;
    for (int i = 1; i <= n; ++i) {
      if (a[i] != b[i]) {
        cnt++;
        if (a[i] == 0) n0++;
        else n1++;
      } else {
        if (a[i] == 0) c0++;
        else c1++;
      }
    }
    if (cnt == 0) {
      puts("0");
      continue;
    }
    if (n1 == 0) {
      if (c0 && c1) puts("2");
      else puts("-1");
      continue;
    }
    if (n1 % 2) {
      puts("1");
    } else {
      puts("2");
    }
  }
  return 0;
}
