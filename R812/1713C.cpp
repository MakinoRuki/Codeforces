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
#define N 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
bool used[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      used[i] = false;
    }
    for (int i = n-1; i >= 0; --i) {
      int rt = (int)sqrt(n)+1;
      for (; rt >= 0; --rt) {
        if (rt * rt - i >= 0 && rt * rt - i < n && !used[rt * rt - i]) {
          a[i] = rt * rt - i;
          used[a[i]] = true;
          break;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      printf("%d", a[i]);
      if (i < n-1) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
