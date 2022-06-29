#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#define N 500
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int main() {
  cin>>n;
  string ans="";
  int cur = 0, cnt=0;
  for (int i = 0; i < n; ++i) {
    if (cnt < 2) {
      ans.push_back(cur+'a');
      cnt++;
    } else {
      cur = !cur;
      ans.push_back(cur+'a');
      cnt=1;
    }
  }
  cout<<ans<<endl;
  return 0;
}
