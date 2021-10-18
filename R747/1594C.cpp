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
#include <stack>
#define eps 1e-7
#define M 502
#define N 50002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int m, k, t;
int n;
string s, c;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    cin>>c;
    cin>>s;
    n = (int)s.size();
    int tot=0;
    for (int i = 0; i < n; ++i) {
      if (s[i] != c[0]) {
        tot++;
      }
    }
    if (tot == 0) {
      puts("0");
      continue;
    }
    bool found=false;
    int id = -1;
    for (int i = 1; i <= n; ++i) {
      int cnt=0;
      for (int j = i; j <= n; j += i) {
        if (s[j-1] != c[0]) {
          cnt++;
        }
      }
      if (cnt == 0) {
        id = i;
        break;
      }
    }
    if (id >= 1) {
      printf("1\n");
      printf("%d\n", id);
      continue;
    }
    puts("2");
    printf("%d %d\n", n, n-1);
  }
  return 0;
}
