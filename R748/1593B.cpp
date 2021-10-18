#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#include <stack>
#define eps 1e-7
#define M 502
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int m, k, t;
ll n;
int a,b,c;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%lld", &n);
    vector<int> ds;
    ds.clear();
    while(n) {
      ds.push_back(n%10);
      n/=10;
    }
    int sz = (int)ds.size();
    int ans = sz+1;
    for (int i = 0; i < sz; ++i) {
      for (int j = i+1; j < sz; ++j) {
        if ((ds[j]*10+ds[i])%25==0) {
          if (j == sz-1 && ds[i] == 0 && ds[j] == 0) {
            continue;
          }
          ans = min(ans, j-1);
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
