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
#define N 500005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i =1; i <= n; ++i) {
      for (int j = 1; j <= i; ++j) {
        if (j == 1 || j == i) {
          printf("1");
        } else {
          printf("0");
        }
        if (j == i) cout<<endl;
        else cout<<" ";
      }
    }
  }
  return 0;
}
