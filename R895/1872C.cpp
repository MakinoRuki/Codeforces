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
#define N 200
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
int d[N], s[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int l,r;
    scanf("%d%d", &l, &r);
    if (l == r) {
      int p=-1;
      for (int i = 2; i * i <= r; ++i) {
        if (r%i == 0) {
          p = i;
          break;
        }
      }
      if (p < 0) {
        puts("-1");
      } else {
        int x = r/p;
        printf("%d %d\n", p, r-p);
      }
    } else {
      if (r%2 == 0) {
        if (r/2 > 1) {
        printf("%d %d\n", r/2, r/2);
        } else {
          puts("-1");
        }
      } else {
        int r2 = r-1;
        if (r2 /2 > 1){
        printf("%d %d\n", r2/2, r2/2);
        } else {
          puts("-1");
        }
      }
    }
  }
  return 0;
}
