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
#define N 100005
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int a,b,c;
    scanf("%d%d%d", &a, &b, &c);
    if (a > b) swap(a,b);
    int dt = b-a;
    if (dt % 2 == 0) dt/=2;
    else dt=dt/2+1;
    int res=(dt+c-1)/c;
    printf("%d\n", res);
  }
  return 0;
}
