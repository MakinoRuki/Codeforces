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
int a[N];
int cnt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    a[1] = 2;
    a[2] = 3;
    for (int i = 3; i <= n; ++i) {
      a[i] = a[i-1] + 1;
      if ((3*a[i]) % (a[i-1]+a[i-2]) == 0) {
        a[i]++;
      }
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d ", a[i]);
    }
    cout<<endl;
  }
  return 0;
}
