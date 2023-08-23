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
bool check(string& s1, string& s2) {
  for (int i = 0; i <= n; ++i) {
    int j;
    for (j = 0; j < n; ++j) {
      if (s1[i+j] != s2[j]) break;
    }
    if (j >= n) return false;
  }
  return true;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    //scanf("%d", &n);
    string s;
    cin>>s;
    n = (int)s.size();
    if (s == "()") {
      puts("NO");
      continue;
    }
    string s1 = "";
    string s2 = "";
    for (int i = 1; i <= n; ++i) {
      s1 += "(";
      s2 += "()";
    }
    for (int i = 1; i <= n; ++i) {
      s1 += ")";
    }
    puts("YES");
    if (check(s1, s)) {
      cout<<s1<<endl;
    } else {
      cout<<s2<<endl;
    }
  }
  return 0;
}
