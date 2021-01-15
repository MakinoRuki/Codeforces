#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
int ans[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    int det=n-k;
    int det2=2*k-n;
    for (int i = 1; i < det2; ++i) {
      ans[i] = i;
    }
    for (int i = det2; i <= k; ++i) {
      ans[i] = k+det2-i;
    }
    for (int i =1 ; i <= k; ++i) {
      printf("%d", ans[i]);
      if (i < k) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
