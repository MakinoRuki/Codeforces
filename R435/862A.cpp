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
#define N 10005
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
  for (int i = 0; i < n; ++i) {
    int y;
    scanf("%d", &y);
    ss.insert(y);
  }
  int ans=0;
  for (int i = 0; i < x; ++i) {
    if (ss.find(i) == ss.end()) {
      ans++;
    }
  }
  if (ss.find(x) != ss.end()) {
    ans++;
  }
  cout<<ans<<endl;
  return 0;
}
