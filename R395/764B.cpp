#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  int dt = n/2;
  for (int i = 1; i <= n/2; ++i) {
    if (i % 2) {
      swap(a[i], a[n+1-i]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d", a[i]);
    if (i < n) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
