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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    bool ok=true;
    int nq=0,na=0;
    for (int i = n-1; i >= 0; --i) {
      if (s[i] == 'A') na++;
      else nq++;
      if (na < nq) {
        ok=false;
        break;
      }
    }
    if (ok) puts("Yes");
    else puts("No");
  }
  return 0;
}
