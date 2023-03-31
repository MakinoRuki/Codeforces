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
#define N 10000002
#define M 520
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int d;
bool check2(string& s) {
  for (int i = 1; i < s.size(); ++i) {
    if (s[i] == s[i-1]) return false;
  }
  return true;
}
bool check(string s1, string s2) {
  while(true) {
    if (check2(s1) && check2(s2)) {
      return true;
    }
    if (s2.size() <= 1) break;
    s1.push_back(s2.back());
    s2.pop_back();
  }
  return false;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    string a,b;
    cin>>a>>b;
    if (check(a, b) || check(b, a)) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}
