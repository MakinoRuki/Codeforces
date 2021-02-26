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
int n, k;
vector<string> ss;
map<int, int> c1, c2;
int main() {
  cin>>n;
  ss.clear();
  int c0=0;
  c1.clear();
  c2.clear();
  for (int i = 1; i <= n; ++i) {
    string s;
    cin>>s;
    ss.push_back(s);
    int j;
    int sum=0;
    for (j = 0; j < s.size(); ++j) {
      if (s[j] == '(') sum++;
      else sum--;
      if (sum < 0) break;
    }
    if (sum == 0) {
      c0++;
    } else if (j >= s.size() && sum > 0) {
      c1[sum]++;
    }
    sum=0;
    for (j = s.size()-1; j >= 0; --j) {
      if (s[j] == ')') sum++;
      else sum--;
      if (sum < 0) break;
    }
    if (j < 0 && sum > 0) {
      c2[sum]++;
    }
  }
 // cout<<c0<<" "<<c1[1]<<" "<<c2[1]<<endl;
  ll ans = (ll)c0*(ll)c0;
  for (auto itr : c1) {
    if (c2.find(itr.first) != c2.end()) {
      ans += (ll)itr.second * (ll)c2[itr.first];
    }
  }
  cout<<ans<<endl;
  return 0;
}
