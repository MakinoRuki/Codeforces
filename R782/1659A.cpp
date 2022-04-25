#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <set>
#include <list>
#include <random>
#define N 300005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int c;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int r,b;
    scanf("%d%d%d", &n, &r, &b);
    int q = r/(b+1);
    int rr = r%(b+1);
    string ans="";
    for (int i = 1; i <= b;++i) {
      if (i <= rr) {
        ans += string(q+1, 'R');
      } else {
        ans += string(q, 'R');
      }
      ans += "B";
    }
    ans += string(q, 'R');
    cout<<ans<<endl;
  }
  return 0;
}
