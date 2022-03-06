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
#define N 3005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int main() {
  cin>>n>>k;
  cin>>s;
  string ans = s;
  int cnt = 1;
  int id = 1;
  while(cnt < k) {
    int i;
    for (i = id; i < ans.size(); ++i) {
      if (ans[i] != s[i-id]) {
        break;
      }
    }
    if (i >= ans.size()) {
      for (int j = i-id; j < s.size(); ++j) {
        ans.push_back(s[j]);
      }
      cnt++;
    }
    id++;
  }
  cout<<ans<<endl;
  return 0;
}
