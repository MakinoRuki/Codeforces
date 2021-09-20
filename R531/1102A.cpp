#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 12
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
ll n, k;
string t;
int main() {
  cin>>n;
  if (n%2 == 0) {
    n /= 2;
    if (n%2 == 0) puts("0");
    else puts("1");
  } else {
    if (n == 1) {
      puts("1");
    } else {
      int m = n-3;
      m /= 2;
      if (m%2 == 0) {
        puts("0");
      } else {
        puts("1");
      }
    }
  }
  return 0;
}
