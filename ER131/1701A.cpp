#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define eps 1e-8
#define N 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
//int a[N];
int a[2][2];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int cnt=0;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        int x;
        scanf("%d", &x);
        if (x) cnt++;
      }
    }
    if (cnt == 0) puts("0");
    else if (cnt == 4) puts("2");
    else puts("1");
  }
  
  return 0;
}
