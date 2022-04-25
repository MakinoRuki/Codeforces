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
int c[N];
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i =1; i <= n; ++i) {
      a[i] = 1;
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &c[i]);
    }
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
      if (i == 1) {
        a[c[i]+1] = 0;
      } else {
        if (a[i] == 1) {
          if (c[i]>0)
          a[c[i]+1] = 0;
          else a[i] = 0;
        } else {
          if (i+c[i] <= n) {
            a[i+c[i]] = 0;
          }
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d", a[i]);
      if (i < n) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
