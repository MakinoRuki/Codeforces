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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    if (n % 2) {
      for (int i = 1; i <= n; ++i) {
        printf("1 ");
      }
      cout<<endl;
    } else {
      printf("1 3 ");
      for (int i = 1; i <= n-2; ++i) {
        printf("2 ");
      }
      cout<<endl;
    }
  }
  return 0;
}
