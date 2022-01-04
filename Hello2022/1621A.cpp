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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
int a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    if (k > (n+1)/2) {
      puts("-1");
    } else {
      vector<string> ans;
      ans.clear();
      for (int i = 0; i < n; ++i) {
        string cur = string(n, '.');
        if (((i%2) == 0) && k > 0) {
          cur[i] = 'R';
          k--;
        }
        ans.push_back(cur);
      }
      for (int i = 0; i < n; ++i) {
        printf("%s\n", ans[i].c_str());
      }
    }
  }
  return 0;
}
