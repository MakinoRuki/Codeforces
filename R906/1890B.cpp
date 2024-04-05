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
#define N 1000005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    string s1,s2;
    cin>>s1>>s2;
    bool ok1=true;
    bool ok2=true;
    int i;
    for (i = 1; i < s1.size(); ++i) {
      if (s1[i] == s1[i-1]) {
        ok1=false;
        break;
      }
    }
    for (int i = 1; i < s2.size(); ++i) {
      if (s2[i] == s2[i-1]) {
        ok2=false;
        break;
      }
    }
    if (ok1) {
      puts("Yes");
      continue;
    }
    if (!ok2) {
      puts("No");
      continue;
    }
    if (s2[0] != s2.back()) {
      puts("No");
      continue;
    }
    ok1=true;
    for (int i = 1; i < s1.size(); ++i) {
      if (s1[i] == s1[i-1]) {
        if (s1[i] == s2[0]) {
          ok1=false;
          break;
        }
      }
    }
    if (!ok1) puts("No");
    else puts("Yes");
  }
  return 0;
}
