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
#define N 200
#define M 2505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      a[i] = i;
    }
    printf("%d\n", n);
    for (int i = 1; i <= n; ++i) {
      swap(a[i], a[1]);
      for (int j = 1; j <= n; ++j) {
        printf("%d", a[j]);
        if (j < n) cout<<" ";
        else cout<<endl;
      }
    }
  }
  return 0;
}
