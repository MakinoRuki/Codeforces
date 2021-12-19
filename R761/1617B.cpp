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
int n, m, k, q;
int t;
string s;
int cnt[26];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    if (n % 2 == 0) {
      printf("%d %d %d\n", n-3, 2, 1);
    } else {
      if ((n/2) % 2 == 0) {
        printf("%d %d %d\n", (n-1)/2-1, (n-1)/2+1, 1);
      } else {
        printf("%d %d %d\n", (n-1)/2-2, (n-1)/2+2, 1);
      }
    }
  }
  return 0;
}
