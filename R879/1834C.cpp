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
int a[N];
int check(string& s1, string& s2) {
  int tot=0;
  for (int i = 0; i < s1.size(); ++i) {
    if (s1[i] != s2[i]) {
      tot++;
    }
  }
  return tot;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s1, s2;
    cin>>s1>>s2;
    int res1=check(s1, s2);
    reverse(s2.begin(), s2.end());
    int res2=check(s1, s2);
    if (res1 % 2) {
      res1 += res1-1;
    } else {
      res1*=2;
    }
    if (res2%2) {
      res2 *= 2;
    } else {
      if (res2 > 0) res2 += res2-1;
      else res2=2;
    }
    printf("%d\n", min(res1,res2));
  }
  return 0;
}
