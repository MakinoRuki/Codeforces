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
int x[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int n;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    vector<int> qs;
    qs.clear();
    for (int i = 1; i <= q; ++i) {
      scanf("%d", &x[i]);
      if (qs.empty() || x[i] < qs.back()) {
        qs.push_back(x[i]);
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < qs.size(); ++j) {
        if ((a[i]%(1<<qs[j])) == 0) {
          a[i] |= (1<<(qs[j]-1));
        }
      }
      printf("%d ", a[i]);
    }
    cout<<endl;
  }
  return 0;
}
