
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
int a[N];
int main() {
  cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      a[i] = n+1-i;
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d " , a[i]);
    }
    cout<<endl;
  }
  return 0;
}
