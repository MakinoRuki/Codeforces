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
#define N 200005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int a,b;
    scanf("%d%d", &a, &b);
    int dt = abs(a-b);
    string ans="";
    int cur = 0;
    if (a < b) cur = 1;
    int tot = 0;
    int ca = 0, cb = 0;
    for (int i = 0; i < a+b; ++i) {
      ans.push_back('0' + cur);
      if (cur) cb++;
      else ca++;
      if (cur == 0) tot++;
      else tot--;
      if (cur == 0) {
        if (cb < b && (ca >= a || abs(tot)>=dt)) {
          cur = !cur;
        }
      } else {
        if (ca < a && (cb >= b || abs(tot)>=dt)) {
          cur = !cur;
        }
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
