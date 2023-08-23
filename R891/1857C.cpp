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
#define N 1000005
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int b[N];
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n*(n-1)/2; ++i) {
      scanf("%d", &b[i]);
    }
    sort(b+1, b+n*(n-1)/2+1);
    int cur=1;
    int id=1;
    for (int i = n-1; i >= 1; --i) {
      a[id++] = b[cur];
      cur += i;
    }
    a[n] = 1000000000;
    for (int i = 1; i <= n; ++i) {
      printf("%d", a[i]);
      if (i < n) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
