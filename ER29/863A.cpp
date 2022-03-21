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
#define M 202
#define N 20000
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
bool check(string t) {
  int l = 0, r = t.size()-1;
  while(l < r) {
    if (t[l] == t[r]) {
      l++;
      r--;
    } else {
      return false;
    }
  }
  return true;
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  int x;
  scanf("%d", &x);
  s.clear();
  while(x) {
    s.push_back(x%10+'0');
    x/=10;
  }
  bool ok = false;
  for (int i = 0; i <= 10; ++i) {
    if (check(s)) {
      ok=true;
      break;
    }
    s.push_back('0');
  }
  if (ok) puts("YES");
  else puts("NO");
  //}
  return 0;
}
