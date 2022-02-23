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
#define M 202
#define N 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
int sum[N];
int main() {
  cin>>n;
  cin>>s;
  memset(sum, 0, sizeof(sum));
  for (int i = 1; i <= n; ++i) {
    sum[i] = sum[i-1] + (s[i-1] == '1');
  }
  map<int, int> ids;
  ids.clear();
  int ans=0;
  ids[0] = 0;
  for (int i = 1; i <= n; ++i) {
    int res = 2*sum[i] - i;
   // if (i == 6) cout<<"x="<<res<<endl;
    if (ids.find(res) != ids.end()) {
      ans = max(ans, i - ids[res]);
    } else {
      ids[res] = i;
    }
  }
  cout<<ans<<endl;
  return 0;
}
