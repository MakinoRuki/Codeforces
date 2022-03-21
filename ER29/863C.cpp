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
#define N 20000
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int as[3][3];
int bs[3][3];
pair<int,int> calc(int x) {
  int a = x/3;
  int b = x % 3;
  if (a == b) {
    return {0,0};
  }
  if ((a + 1) % 3 == b) {
    return {0, 1};
  }
  return {1, 0};
}
int main() {
  ll k;
  int a,b;
  scanf("%lld%d%d", &k, &a, &b);
  a--;
  b--;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      scanf("%d", &as[i][j]);
      as[i][j]--;
    }
  }
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      scanf("%d", &bs[i][j]);
      bs[i][j]--;
    }
  }
  int cur = a*3 + b;
  vector<int> v;
  v.clear();
  set<int> ss;
  while(true) {
    v.push_back(cur);
    ss.insert(cur);
    int a1 = cur/3;
    int b1= cur % 3;
    cur = as[a1][b1] * 3 + bs[a1][b1];
   // cout<<"cur="<<cur<<" "<<a1<<" "<<b1<<endl;
    if (ss.find(cur) != ss.end()) {
      break;
    }
  }
  ll sa = 0LL;
  ll sb = 0LL;
  int id = 0;
  for (id = 0; id < v.size(); ++id) {
    if (v[id] == cur) {
      break;
    }
  }
  ll ta = 0LL;
  ll tb = 0LL;
  for (int i = 0; i < min(k, (ll)id); ++i) {
    auto pr = calc(v[i]);
    ta += pr.first;
    tb += pr.second;
  }
  if (k <= id) {
    cout<<ta<<" "<<tb<<endl;
    return 0;
  }
  k -= (id);
  for (int i = id; i < v.size(); ++i) {
    auto pr = calc(v[i]);
    sa += pr.first;
    sb += pr.second;
  }
  int sz = v.size()-id;
  ta += k / sz * sa;
  tb += k / sz * sb;
  k %= sz;
  for (int i = 0; i <k; ++i) {
    auto pr = calc(v[i+id]);
    ta += pr.first;
    tb += pr.second;
  }
  cout<<ta<<" "<<tb<<endl;
  return 0;
}
