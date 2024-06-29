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
#define N 500005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x1,y1;
    int x2,y2;
    scanf("%d%d", &x1, &y1);
    scanf("%d%d", &x2, &y2);
    if (x1 > y1 && x2 > y2) {
      puts("YES");
    } else if (x1 < y1 && x2 < y2) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}
