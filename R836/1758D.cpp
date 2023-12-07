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
#define N 300005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
ll a[N];
int ans[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    ans[1] = 3*n;
    ans[n] = 5*n;
    int l = 2, r = n-1;
    while(l <= r) {
      if (l == r) {
        ans[l] = 4*n;
        break;
      }
      ans[l] = ans[l-1]+1;
      ans[r] = ans[r+1]-1;
      l++;
      r--;
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d ", ans[i]);
    }
    cout<<endl;
  }
  return 0;
}
