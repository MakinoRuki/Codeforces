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
#define M 500005
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
bool check(string x) {
  int l = 0, r = x.size()-1;
  while(l < r) {
    if (x[l] == x[r]) {
      l++;
      r--;
    } else {
      return false;
    }
  }
  return true;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    cin>>s;
    if (check(s)) {
      puts("1");
    } else {
      if (k == 0) puts("1");
      else puts("2");
    }
  }
  return 0;
}
