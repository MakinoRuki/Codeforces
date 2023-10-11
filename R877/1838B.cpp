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
#define N 200010
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
int p[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int id1=0,id2=0,idn=0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &p[i]);
      if (p[i] == 1) id1 = i;
      if (p[i] == 2) id2 = i;
      if (p[i] == n) idn = i;
    }
    if (abs(id1-id2)==1) {
      if (id1 < id2) {
        if (idn < id1) {
          printf("%d %d\n", id1, idn);
        } else {
          printf("%d %d\n", id2, idn);
        }
      } else {
        if (idn < id2) {
          printf("%d %d\n", id2, idn);
        } else {
          printf("%d %d\n", id1, idn);
        }
      }
    } else {
      printf("%d %d\n", min(id1,id2)+1, idn);
    }
  }
  return 0;
}
