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
#define N 2000
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
ll a[N];
int main() {
  a[1] = 1;
  int cur = 1;
  while(true) {
    if (a[cur] * 3LL <= 1000000000LL) {
      ++cur;
      a[cur] = a[cur-1] * 3LL; 
    } else {
      break;
    }
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    if (n <= cur) {
      puts("YES");
      for (int i = 1; i <= n; ++i) {
        printf("%lld", a[i]);
        if (i < n) cout<<" ";
        else cout<<endl;
      }
    } else {
      puts("NO");
    }
  }
  return 0;
}
