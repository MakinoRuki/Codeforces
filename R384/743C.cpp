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
#define N 500005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m;
ll k;
int t;
string s;
int a[N];
int main() {
  cin>>n;
  if (n == 1) {
    puts("-1");
    return 0;
  }
  printf("%d %d %d\n", n, n+1, n*(n+1));
  return 0;
}
