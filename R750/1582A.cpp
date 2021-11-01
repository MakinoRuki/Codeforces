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
#define M 21
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, h;
ll k;
int q;
int a,b,c;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &a, &b, &c);
    int x=(a%2);
    int y=(b%2);
    int z=(c%2);
    if (x && !y && !z) {
      puts("1");
    } else if (!x && !y && z) {
      puts("1");
    } else if (x && y && !z) {
      puts("1");
    } else if (!x && y && z) {
      puts("1");
    } else {
      puts("0");
    }
  }
  return 0;
}
