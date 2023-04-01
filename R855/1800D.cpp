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
#define M 22
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    int tot=n-1;
    for (int i = 2; i < n; i += 2) {
      if (s[i] == s[i-2]) tot--;
    }
    for (int i =3; i < n; i += 2) {
      if (s[i] == s[i-2]) tot--;
    }
    printf("%d\n", tot);
  }
  return 0;
}
