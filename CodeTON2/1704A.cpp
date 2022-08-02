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
#define N 100005
#define M 100005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    string s1, s2;
    cin>>s1>>s2;
    if (s1.substr(n-m+1, m-1) != s2.substr(1, m-1)) {
      puts("NO");
      continue;
    }
    bool found=false;
    for (int i = 0; i < n-m+1; ++i) {
      if (s1[i] == s2[0]) {
        found=true;
        break;
      }
    }
    if (found) puts("YES");
    else puts("NO");
  }
  return 0;
}
