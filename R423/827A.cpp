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
#define M 500005
#define N 1000005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q, p;
int l, r;
int t;
string s;
map<int, string> mp;
int main() {
  cin>>n;
  string ans = "";
  s.clear();
  vector<pair<int,int>> rk;
  rk.clear();
  vector<string> ss;
  ss.clear();
  for (int i = 1; i <= n; ++i) {
    cin>>s;
    scanf("%d", &k);
    m = (int)s.size();
    ss.push_back(s);
    for (int j = 1; j <= k; ++j) {
      int x;
      scanf("%d", &x);
      rk.push_back(make_pair(x, i));
    }
  }
  sort(rk.begin(), rk.end());
  for (int i = 0; i < rk.size(); ++i) {
    int st = rk[i].first;
    int id = rk[i].second;
    while(ans.size() < st-1) {
      ans.push_back('a');
    }
    int bg = ans.size()+1;
    int ed = st + ss[id-1].size()-1;
    if (bg > ed) {
      continue;
    }
    bg -= st;
    ed -= st;
  //  cout<<id<<" "<<bg<<" "<<ed<<endl;
    for (int j = bg; j <= ed; ++j) {
      if (ans.size() < st+j) ans.push_back('a');
      ans[st+j-1] = ss[id-1][j];
    //  cout<<st+j-1<<" "<<ss[id-1][j]<<endl;
    }
  }
  cout<<ans<<endl;
  return 0;
}
