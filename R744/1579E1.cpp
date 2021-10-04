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
#define M 105
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n, m, k;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    deque<int> dq;
    for (int i = 1; i <= n; ++i) {
      if (dq.empty()) {
        dq.push_back(a[i]);
      } else if (a[i] < dq.front()) {
        dq.push_front(a[i]);
      } else {
        dq.push_back(a[i]);
      }
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d", dq.front());
      dq.pop_front();
      if (i < n) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
