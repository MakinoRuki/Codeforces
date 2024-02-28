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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &a, &b);
    bool ok=false;
    if ((a%2)==0) {
        if (b!=a/2) ok=true;
    }
    if ((b%2) == 0) {
        if (a!=b/2) ok=true;
    }
    if (ok) puts("Yes");
    else puts("No");
  }
  return 0;
}
