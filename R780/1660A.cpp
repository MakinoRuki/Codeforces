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
#define M 202
#define N 300005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int m, k, q;
int n;
int t;
int c;
int main() {
  cin>>t;
  for (int cas=1;cas<=t; ++cas) {
    int a,b;
    scanf("%d%d", &a, &b);
    if (a == 0) {
      puts("1");
    } else if (b == 0) {
      printf("%d\n", a+1);
    } else {
      printf("%d\n", a+2*b+1);
    }
  }
  return 0;
}
