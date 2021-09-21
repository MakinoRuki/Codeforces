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
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
string s1, s2;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int a,b,c,m;
    scanf("%d%d%d%d", &a, &b, &c, &m);
    int tot=a+b+c;
    int maxv=max(max(b,c), a);
    tot -= maxv;
    int ub = a-1+b-1+c-1;
    int lb = max(0, maxv - tot - 1);
    if (m >= lb && m <= ub) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}
