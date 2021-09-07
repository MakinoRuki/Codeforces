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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
int main() {
  int x;
  cin>>n>>x;
  set<int> ss;
  ss.clear();
  if (n == 1) {
    puts("YES");
    printf("%d\n", x);
  } else if (n==2) {
    if (x == 0) {
      puts("NO");
    } else {
      puts("YES");
      printf("%d %d\n", 0, x);
    }
  } else {
    int res = 0;
    for (int i = 0; i < n-1; ++i) {
      ss.insert(i);
      res ^= i;
    }
    int v = res ^ x;
    if (ss.find(v) == ss.end()) {
      ss.insert(v);
    } else {
      ss.erase(0);
      ss.insert((1<<19));
      ss.erase(1);
      ss.insert((1<<18)+1);
      v ^= (1<<19);
      v ^= (1<<18);
      ss.insert(v);
    }
    puts("YES");
    vector<int> ans(ss.begin(), ss.end());
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d", ans[i]);
      if (i < ans.size()-1) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
