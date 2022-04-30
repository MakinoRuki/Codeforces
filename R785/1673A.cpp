#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <list>
#include <random>
#define N 400005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int main() {
  cin>>t;
  for (int cas=1;cas<=t; ++cas) {
    string s;
    cin>>s;
    n = (int)s.size();
    int tot=0;
    for (int i = 0; i < n; ++i) {
      int c = s[i]-'a'+1;
      tot +=c;
    }
    if (n % 2 == 0) {
      printf("Alice %d\n", tot);
    } else {
      if (n == 1) {
        printf("Bob %d\n", tot);
      } else {
        int c1 = s[0]-'a'+1;
        int c2 = s[n-1]-'a'+1;
        int sa = 0, sb = 0;
        if (tot - c1 > tot - c2) {
          sa = tot - c1;
          sb = c1;
        } else {
          sa = tot - c2;
          sb = c2;
        }
        if (sa > sb) {
          printf("Alice %d\n", sa-sb);
        } else {
          printf("Bob %d\n", sb-sa);
        }
      }
    }
  }
  return 0;
}
