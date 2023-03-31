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
#define N 200005
#define M 520
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
bool check(string& s1, string& s2) {
  for (int i = 0; i < s1.size(); ++i) {
    int sz = (int)s2.size();
    if (i + sz - 1  >= s1.size()) {
      break;
    }
    int j;
    for (j = 0; j < sz; ++j) {
      if (s1[i+j] != s2[j]) {
        break;
      }
    }
    if (j >= sz) return true;
  }
  return false;
}
int main() {
  cin>>t;
  string ts = "FBFFBFFBFBFFBFFBFBFFBFFB";
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    if (check(ts, s)) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}
